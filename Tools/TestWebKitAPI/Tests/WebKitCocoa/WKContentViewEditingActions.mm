/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "config.h"

#if PLATFORM(IOS_FAMILY)

#import "InstanceMethodSwizzler.h"
#import "PlatformUtilities.h"
#import "Test.h"
#import "TestInputDelegate.h"
#import "TestNavigationDelegate.h"
#import "TestWKWebView.h"
#import "UIKitSPI.h"
#import "WKWebViewConfigurationExtras.h"
#import <WebKit/WKWebViewConfigurationPrivate.h>
#import <WebKit/WebKit.h>
#import <wtf/RetainPtr.h>

TEST(WebKit, WKContentViewEditingActions)
{
    [UIPasteboard generalPasteboard].items = @[];

    RetainPtr<TestWKWebView> webView = adoptNS([[TestWKWebView alloc] initWithFrame:NSMakeRect(0, 0, 800, 600)]);

    [webView synchronouslyLoadTestPageNamed:@"rich-and-plain-text"];

    [webView stringByEvaluatingJavaScript:@"selectPlainText()"];

    UIView *contentView = [webView wkContentView];

    __block bool done = false;

    [webView _doAfterNextPresentationUpdate:^ {
        if ([contentView canPerformAction:@selector(copy:) withSender:nil])
            [contentView copy:nil];

        [webView _doAfterNextPresentationUpdate:^ {
            done = true;
        }];
    }];

    TestWebKitAPI::Util::run(&done);

    EXPECT_WK_STREQ("Hello world", [[UIPasteboard generalPasteboard] string]);
}

TEST(WebKit, InvokeShareWithoutSelection)
{
    auto webView = adoptNS([[TestWKWebView alloc] initWithFrame:CGRectMake(0, 0, 320, 568)]);
    [webView synchronouslyLoadTestPageNamed:@"simple"];
    [[webView textInputContentView] _share:nil];
    [webView waitForNextPresentationUpdate];
}

#if ENABLE(IMAGE_ANALYSIS)

#if ENABLE(APP_HIGHLIGHTS)

TEST(WebKit, AppHighlightsInImageOverlays)
{
    auto configuration = retainPtr([WKWebViewConfiguration _test_configurationWithTestPlugInClassName:@"WebProcessPlugInWithInternals" configureJSCForTesting:YES]);
    [configuration _setAppHighlightsEnabled:YES];

    auto webView = adoptNS([[TestWKWebView alloc] initWithFrame:NSMakeRect(0, 0, 800, 600) configuration:configuration.get()]);
    [webView synchronouslyLoadTestPageNamed:@"simple-image-overlay"];
    [webView stringByEvaluatingJavaScript:@"selectImageOverlay()"];
    [webView waitForNextPresentationUpdate];

    auto createHighlightForCurrentQuickNoteWithRangeSelector = NSSelectorFromString(@"createHighlightForCurrentQuickNoteWithRange:");
    auto createHighlightForNewQuickNoteWithRangeSelector = NSSelectorFromString(@"createHighlightForNewQuickNoteWithRange:");

    auto contentView = [webView textInputContentView];
    EXPECT_NULL([contentView targetForAction:createHighlightForCurrentQuickNoteWithRangeSelector withSender:nil]);
    EXPECT_NULL([contentView targetForAction:createHighlightForNewQuickNoteWithRangeSelector withSender:nil]);

    [webView synchronouslyLoadTestPageNamed:@"simple"];
    [webView selectAll:nil];
    [webView waitForNextPresentationUpdate];
    EXPECT_NULL([contentView targetForAction:createHighlightForCurrentQuickNoteWithRangeSelector withSender:nil]);
    EXPECT_EQ([contentView targetForAction:createHighlightForNewQuickNoteWithRangeSelector withSender:nil], contentView);
}

#endif // ENABLE(APP_HIGHLIGHTS)

static BOOL gCanPerformActionWithSenderResult = NO;
static BOOL canPerformActionWithSender(id /* instance */, SEL, SEL /* action */, id /* sender */)
{
    return gCanPerformActionWithSenderResult;
}

TEST(WebKit, CaptureTextFromCamera)
{
    gCanPerformActionWithSenderResult = YES;
    InstanceMethodSwizzler swizzler { UIResponder.class, @selector(canPerformAction:withSender:), reinterpret_cast<IMP>(canPerformActionWithSender) };

    auto inputDelegate = adoptNS([[TestInputDelegate alloc] init]);
    [inputDelegate setFocusStartsInputSessionPolicyHandler:[] (WKWebView *, id <_WKFocusedElementInfo>) {
        return _WKFocusStartsInputSessionPolicyAllow;
    }];

    auto webView = adoptNS([[TestWKWebView alloc] initWithFrame:NSMakeRect(0, 0, 800, 600)]);
    [webView _setInputDelegate:inputDelegate.get()];
    auto contentView = [webView textInputContentView];

    [webView synchronouslyLoadHTMLString:@"<input value='foo' autofocus><input value='bar' readonly>"];
    [webView waitForNextPresentationUpdate];
    EXPECT_EQ([webView targetForAction:@selector(captureTextFromCamera:) withSender:nil], contentView);
    EXPECT_TRUE([webView canPerformAction:@selector(captureTextFromCamera:) withSender:nil]);

    [webView selectAll:nil];
    [webView waitForNextPresentationUpdate];
    EXPECT_TRUE([webView canPerformAction:@selector(captureTextFromCamera:) withSender:nil]);
    EXPECT_FALSE([webView canPerformAction:@selector(captureTextFromCamera:) withSender:UIMenuController.sharedMenuController]);

    [webView collapseToEnd];
    [webView waitForNextPresentationUpdate];
    EXPECT_TRUE([webView canPerformAction:@selector(captureTextFromCamera:) withSender:nil]);

    gCanPerformActionWithSenderResult = NO;
    EXPECT_FALSE([webView canPerformAction:@selector(captureTextFromCamera:) withSender:nil]);

    gCanPerformActionWithSenderResult = YES;
    [webView objectByEvaluatingJavaScript:@"document.querySelector('input[readonly]').focus()"];
    [webView waitForNextPresentationUpdate];
    EXPECT_FALSE([webView canPerformAction:@selector(captureTextFromCamera:) withSender:nil]);
}

#endif // ENABLE(IMAGE_ANALYSIS)

#endif // PLATFORM(IOS_FAMILY)
