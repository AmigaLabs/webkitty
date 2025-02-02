/*
 * Copyright (C) 2006, 2007, 2014, 2015 Apple Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebInspectorClient_h
#define WebInspectorClient_h

#include <JavaScriptCore/InspectorFrontendChannel.h>
#include <WebCore/InspectorClient.h>
#include <WebCore/InspectorFrontendClientLocal.h>

namespace WebCore {
class CertificateInfo;
class Page;
class PageOverlay;
}

namespace WebKit {

class WebInspectorFrontendClient;
class WebNodeHighlight;
class WebPage;

class WebInspectorClient final : public WebCore::InspectorClient, public Inspector::FrontendChannel {
public:
    explicit WebInspectorClient(WebPage*);

    // InspectorClient API.
    void inspectedPageDestroyed() override;

    Inspector::FrontendChannel* openLocalFrontend(WebCore::InspectorController*) override;
    void bringFrontendToFront() override;

    void highlight() override;
    void hideHighlight() override;

	void inspectedPageWillBeDestroyed();
	void releaseFrontend();
	void closeInspector();

    // FrontendChannel API.
    ConnectionType connectionType() const override { return ConnectionType::Local; }
    void sendMessageToFrontend(const WTF::String&) override;

private:
    virtual ~WebInspectorClient();
    
private:
	WebPage *m_inspectedPage;
    std::unique_ptr<WebInspectorFrontendClient> m_frontendClient;
};
}

#endif // !defined(WebInspectorClient_h)
