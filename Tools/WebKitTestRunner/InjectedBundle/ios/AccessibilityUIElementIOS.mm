/*
 * Copyright (C) 2014 Apple Inc. All rights reserved.
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
#import "AccessibilityUIElement.h"

#import "AccessibilityCommonMac.h"
#import "AccessibilityNotificationHandler.h"
#import "InjectedBundle.h"
#import "InjectedBundlePage.h"
#import <Foundation/Foundation.h>
#import <JavaScriptCore/JSStringRefCF.h>
#import <UIKit/UIKit.h>
#import <WebCore/TextGranularity.h>
#import <WebKit/WKBundleFrame.h>
#import <wtf/RetainPtr.h>
#import <wtf/Vector.h>
#import <wtf/cocoa/VectorCocoa.h>

typedef void (*AXPostedNotificationCallback)(id element, NSString* notification, void* context);

@interface NSObject (UIAccessibilityHidden)
- (id)accessibilityHitTest:(CGPoint)point;
- (id)accessibilityLinkedElement;
- (id)accessibilityTitleElement;
- (NSRange)accessibilityColumnRange;
- (NSRange)accessibilityRowRange;
- (id)accessibilityElementForRow:(NSInteger)row andColumn:(NSInteger)column;
- (NSURL *)accessibilityURL;
- (NSArray *)accessibilityHeaderElements;
- (NSString *)accessibilityPlaceholderValue;
- (NSString *)stringForRange:(NSRange)range;
- (NSAttributedString *)attributedStringForRange:(NSRange)range;
- (NSAttributedString *)attributedStringForElement;
- (NSArray *)elementsForRange:(NSRange)range;
- (NSString *)selectionRangeString;
- (CGPoint)accessibilityClickPoint;
- (void)accessibilityModifySelection:(WebCore::TextGranularity)granularity increase:(BOOL)increase;
- (NSRange)_accessibilitySelectedTextRange;
- (void)_accessibilitySetSelectedTextRange:(NSRange)range;
- (BOOL)accessibilityReplaceRange:(NSRange)range withText:(NSString *)string;
- (BOOL)accessibilityInsertText:(NSString *)text;
- (void)accessibilitySetPostedNotificationCallback:(AXPostedNotificationCallback)function withContext:(void*)context;
- (CGFloat)_accessibilityMinValue;
- (CGFloat)_accessibilityMaxValue;
- (void)_accessibilitySetValue:(NSString *)value;
- (void)_accessibilityActivate;
- (UIAccessibilityTraits)_axSelectedTrait;
- (UIAccessibilityTraits)_axTextAreaTrait;
- (UIAccessibilityTraits)_axSearchFieldTrait;
- (NSString *)accessibilityARIACurrentStatus;
- (NSUInteger)accessibilityRowCount;
- (NSUInteger)accessibilityColumnCount;
- (NSUInteger)accessibilityARIARowCount;
- (NSUInteger)accessibilityARIAColumnCount;
- (NSUInteger)accessibilityARIARowIndex;
- (NSUInteger)accessibilityARIAColumnIndex;
- (BOOL)accessibilityIsInDescriptionListDefinition;
- (BOOL)accessibilityIsInDescriptionListTerm;
- (UIAccessibilityTraits)_axContainedByFieldsetTrait;
- (id)_accessibilityFieldsetAncestor;
- (BOOL)_accessibilityHasTouchEventListener;
- (NSString *)accessibilityExpandedTextValue;
- (NSString *)accessibilitySortDirection;
- (BOOL)accessibilityIsExpanded;
- (NSUInteger)accessibilityBlockquoteLevel;
- (NSArray *)accessibilityFindMatchingObjects:(NSDictionary *)parameters;
- (NSArray<NSString *> *)accessibilitySpeechHint;
- (BOOL)_accessibilityIsStrongPasswordField;
- (CGRect)accessibilityVisibleContentRect;
- (NSString *)accessibilityTextualContext;
- (NSString *)accessibilityRoleDescription;
- (BOOL)accessibilityHasPopup;
- (NSString *)accessibilityPopupValue;
- (NSString *)accessibilityColorStringValue;

// TextMarker related
- (NSArray *)textMarkerRange;
- (NSInteger)lengthForTextMarkers:(NSArray *)textMarkers;
- (NSString *)stringForTextMarkers:(NSArray *)markers;
- (id)startOrEndTextMarkerForTextMarkers:(NSArray*)textMarkers isStart:(BOOL)isStart;
- (NSArray *)textMarkerRangeForMarkers:(NSArray *)textMarkers;
- (NSInteger)positionForTextMarker:(id)marker;
- (id)nextMarkerForMarker:(id)marker;
- (id)previousMarkerForMarker:(id)marker;
- (id)accessibilityObjectForTextMarker:(id)marker;
- (id)lineStartMarkerForMarker:(id)marker;
- (id)lineEndMarkerForMarker:(id)marker;
- (NSArray *)misspellingTextMarkerRange:(NSArray *)startTextMarkerRange forward:(BOOL)forward;
- (NSArray *)textMarkerRangeFromMarkers:(NSArray *)markers withText:(NSString *)text;
- (BOOL)_accessibilityIsInTableCell;
@end

@interface NSObject (WebAccessibilityObjectWrapperPrivate)
- (CGPathRef)_accessibilityPath;
@end

@implementation NSString (JSStringRefAdditions)

+ (NSString *)stringWithJSStringRef:(JSStringRef)jsStringRef
{
    if (!jsStringRef)
        return nil;
    
    return CFBridgingRelease(JSStringCopyCFString(kCFAllocatorDefault, jsStringRef));
}

- (JSRetainPtr<JSStringRef>)createJSStringRef
{
    return adopt(JSStringCreateWithCFString((__bridge CFStringRef)self));
}

@end

namespace WTR {

static JSRetainPtr<JSStringRef> createEmptyJSString()
{
    return adopt(JSStringCreateWithCharacters(nullptr, 0));
}

static JSRetainPtr<JSStringRef> concatenateAttributeAndValue(NSString *attribute, NSString *value)
{
    Vector<UniChar> buffer([attribute length]);
    [attribute getCharacters:buffer.data()];
    buffer.append(':');
    buffer.append(' ');

    Vector<UniChar> valueBuffer([value length]);
    [value getCharacters:valueBuffer.data()];
    buffer.appendVector(valueBuffer);

    return adopt(JSStringCreateWithCharacters(buffer.data(), buffer.size()));
}
    
AccessibilityUIElement::AccessibilityUIElement(PlatformUIElement element)
    : m_element(element)
{
}

AccessibilityUIElement::AccessibilityUIElement(const AccessibilityUIElement& other)
    : JSWrappable()
    , m_element(other.m_element)
{
}

AccessibilityUIElement::~AccessibilityUIElement()
{
}

bool AccessibilityUIElement::isEqual(AccessibilityUIElement* otherElement)
{
    if (!otherElement)
        return false;
    return platformUIElement() == otherElement->platformUIElement();
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::headerElementAtIndex(unsigned index)
{
    NSArray *headers = [m_element accessibilityHeaderElements];
    if (index < [headers count])
        return AccessibilityUIElement::create([headers objectAtIndex:index]);
    
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::linkedElement()
{
    id linkedElement = [m_element accessibilityLinkedElement];
    if (linkedElement)
        return AccessibilityUIElement::create(linkedElement);
    
    return nullptr;
}

void AccessibilityUIElement::getLinkedUIElements(Vector<RefPtr<AccessibilityUIElement> >& elementVector)
{
}

void AccessibilityUIElement::getDocumentLinks(Vector<RefPtr<AccessibilityUIElement> >& elementVector)
{
}

void AccessibilityUIElement::getChildren(Vector<RefPtr<AccessibilityUIElement> >& elementVector)
{
    NSInteger childCount = [m_element accessibilityElementCount];
    for (NSInteger k = 0; k < childCount; ++k)
        elementVector.append(AccessibilityUIElement::create([m_element accessibilityElementAtIndex:k]));
}

void AccessibilityUIElement::getChildrenWithRange(Vector<RefPtr<AccessibilityUIElement> >& elementVector, unsigned location, unsigned length)
{
    NSUInteger childCount = [m_element accessibilityElementCount];
    for (NSUInteger k = location; k < childCount && k < (location+length); ++k)
        elementVector.append(AccessibilityUIElement::create([m_element accessibilityElementAtIndex:k]));
}

int AccessibilityUIElement::childrenCount()
{
    Vector<RefPtr<AccessibilityUIElement>> children;
    getChildren(children);

    return children.size();
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::elementAtPoint(int x, int y)
{
    id element = [m_element accessibilityHitTest:CGPointMake(x, y)];
    if (!element)
        return nil;
    
    return AccessibilityUIElement::create(element);
}
    
static JSValueRef convertElementsToObjectArray(JSContextRef context, const Vector<RefPtr<AccessibilityUIElement>>& elements)
{
    auto array = JSObjectMakeArray(context, 0, nullptr, nullptr);
    auto size = elements.size();
    for (size_t i = 0; i < size; ++i)
        JSObjectSetPropertyAtIndex(context, array, i, JSObjectMake(context, elements[i]->wrapperClass(), elements[i].get()), nullptr);
    return array;
}
JSValueRef AccessibilityUIElement::elementsForRange(unsigned location, unsigned length)
{
    WKBundleFrameRef mainFrame = WKBundlePageGetMainFrame(InjectedBundle::singleton().page()->page());
    JSContextRef context = WKBundleFrameGetJavaScriptContext(mainFrame);
    NSArray *elementsForRange = [m_element elementsForRange:NSMakeRange(location, length)];
    return convertElementsToObjectArray(context, makeVector<RefPtr<AccessibilityUIElement>>(elementsForRange));
}

unsigned AccessibilityUIElement::indexOfChild(AccessibilityUIElement* element)
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::childAtIndex(unsigned index)
{
    Vector<RefPtr<AccessibilityUIElement> > children;
    getChildrenWithRange(children, index, 1);

    if (children.size() == 1)
        return children[0];
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::linkedUIElementAtIndex(unsigned index)
{
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::ariaOwnsElementAtIndex(unsigned index)
{
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::ariaFlowToElementAtIndex(unsigned index)
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::ariaControlsElementAtIndex(unsigned index)
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::disclosedRowAtIndex(unsigned index)
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::rowAtIndex(unsigned index)
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::selectedChildAtIndex(unsigned index) const
{
    return nullptr;
}

unsigned AccessibilityUIElement::selectedChildrenCount() const
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::selectedRowAtIndex(unsigned index)
{
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::titleUIElement()
{
    id titleElement = [m_element accessibilityTitleElement];
    if (titleElement)
        return AccessibilityUIElement::create(titleElement);
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::parentElement()
{
    return nil;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::disclosedByRow()
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfLinkedUIElements()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfDocumentLinks()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfChildren()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::allAttributes()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::stringDescriptionOfAttributeValue(JSStringRef attribute)
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::stringAttributeValue(JSStringRef attribute)
{
    if (JSStringIsEqualToUTF8CString(attribute, "AXPlaceholderValue"))
        return [[m_element accessibilityPlaceholderValue] createJSStringRef];

    if (JSStringIsEqualToUTF8CString(attribute, "AXRoleDescription"))
        return [[m_element accessibilityRoleDescription] createJSStringRef];

    if (JSStringIsEqualToUTF8CString(attribute, "AXColorStringDescription"))
        return [[m_element accessibilityColorStringValue] createJSStringRef];

    if (JSStringIsEqualToUTF8CString(attribute, "AXARIACurrent"))
        return [[m_element accessibilityARIACurrentStatus] createJSStringRef];

    if (JSStringIsEqualToUTF8CString(attribute, "AXExpandedTextValue"))
        return [[m_element accessibilityExpandedTextValue] createJSStringRef];
    
    if (JSStringIsEqualToUTF8CString(attribute, "AXSortDirection"))
        return [[m_element accessibilitySortDirection] createJSStringRef];
    
    if (JSStringIsEqualToUTF8CString(attribute, "AXVisibleContentRect")) {
        CGRect screenRect = [m_element accessibilityVisibleContentRect];
        NSString *rectStr = [NSString stringWithFormat:@"{%.2f, %.2f, %.2f, %.2f}", screenRect.origin.x, screenRect.origin.y, screenRect.size.width, screenRect.size.height];
        return [rectStr createJSStringRef];
    }

    if (JSStringIsEqualToUTF8CString(attribute, "AXTextualContext"))
        return [[m_element accessibilityTextualContext] createJSStringRef];
    
    return createEmptyJSString();
}

double AccessibilityUIElement::numberAttributeValue(JSStringRef attribute)
{
    // Support test for table related attributes.
    if (JSStringIsEqualToUTF8CString(attribute, "AXARIAColumnCount"))
        return [m_element accessibilityARIAColumnCount];
    if (JSStringIsEqualToUTF8CString(attribute, "AXARIARowCount"))
        return [m_element accessibilityARIARowCount];
    if (JSStringIsEqualToUTF8CString(attribute, "AXARIAColumnIndex"))
        return [m_element accessibilityARIAColumnIndex];
    if (JSStringIsEqualToUTF8CString(attribute, "AXARIARowIndex"))
        return [m_element accessibilityARIARowIndex];
    if (JSStringIsEqualToUTF8CString(attribute, "AXBlockquoteLevel"))
        return [m_element accessibilityBlockquoteLevel];
    
    return 0;
}

JSValueRef AccessibilityUIElement::uiElementArrayAttributeValue(JSStringRef attribute) const
{
    return nullptr;
}

JSValueRef AccessibilityUIElement::rowHeaders() const
{
    return nullptr;
}

JSValueRef AccessibilityUIElement::columnHeaders() const
{
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::uiElementAttributeValue(JSStringRef attribute) const
{
    return nullptr;
}

bool AccessibilityUIElement::boolAttributeValue(JSStringRef attribute)
{
    if (JSStringIsEqualToUTF8CString(attribute, "AXHasTouchEventListener"))
        return [m_element _accessibilityHasTouchEventListener];
    if (JSStringIsEqualToUTF8CString(attribute, "AXIsStrongPasswordField"))
        return [m_element _accessibilityIsStrongPasswordField];
    return false;
}

bool AccessibilityUIElement::isAttributeSettable(JSStringRef attribute)
{
    return false;
}

bool AccessibilityUIElement::isAttributeSupported(JSStringRef attribute)
{
    return false;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::parameterizedAttributeNames()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::role()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::subrole()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::roleDescription()
{
    return concatenateAttributeAndValue(@"AXRoleDescription", [m_element accessibilityRoleDescription]);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::computedRoleString()
{
    // FIXME: implement
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::title()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::description()
{
    return concatenateAttributeAndValue(@"AXLabel", [m_element accessibilityLabel]);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::orientation() const
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::stringValue()
{
    return concatenateAttributeAndValue(@"AXValue", [m_element accessibilityValue]);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::language()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::helpText() const
{
    return concatenateAttributeAndValue(@"AXHint", [m_element accessibilityHint]);
}

double AccessibilityUIElement::x()
{
    CGRect frame = [m_element accessibilityFrame];
    return frame.origin.x;
}

double AccessibilityUIElement::y()
{
    CGRect frame = [m_element accessibilityFrame];
    return frame.origin.y;
}

double AccessibilityUIElement::width()
{
    CGRect frame = [m_element accessibilityFrame];
    return frame.size.width;
}

double AccessibilityUIElement::height()
{
    CGRect frame = [m_element accessibilityFrame];
    return frame.size.height;
}

double AccessibilityUIElement::clickPointX()
{
    return [m_element accessibilityClickPoint].x;
}

double AccessibilityUIElement::clickPointY()
{
    return [m_element accessibilityClickPoint].y;
}

double AccessibilityUIElement::intValue() const
{
    return 0;
}

double AccessibilityUIElement::minValue()
{
    return [m_element _accessibilityMinValue];
}

double AccessibilityUIElement::maxValue()
{
    return [m_element _accessibilityMaxValue];
}


JSRetainPtr<JSStringRef> AccessibilityUIElement::valueDescription()
{
    return createEmptyJSString();
}

int AccessibilityUIElement::insertionPointLineNumber()
{
    return -1;
}

bool AccessibilityUIElement::isPressActionSupported()
{
    return false;
}

bool AccessibilityUIElement::isIncrementActionSupported()
{
    return false;
}

bool AccessibilityUIElement::isDecrementActionSupported()
{
    return false;
}

bool AccessibilityUIElement::isEnabled()
{
    return false;
}

bool AccessibilityUIElement::isRequired() const
{
    return false;
}

bool AccessibilityUIElement::isFocused() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isSelected() const
{
    UIAccessibilityTraits traits = [m_element accessibilityTraits];
    return (traits & [m_element _axSelectedTrait]) == [m_element _axSelectedTrait];
}

bool AccessibilityUIElement::isSelectedOptionActive() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isIndeterminate() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isExpanded() const
{
    return [m_element accessibilityIsExpanded];
}

bool AccessibilityUIElement::isChecked() const
{
    return false;
}

int AccessibilityUIElement::hierarchicalLevel() const
{
    return 0;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::classList() const
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::speakAs()
{
    return [[[m_element accessibilitySpeechHint] componentsJoinedByString:@", "] createJSStringRef];
}

bool AccessibilityUIElement::ariaIsGrabbed() const
{
    return false;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::ariaDropEffects() const
{
    return createEmptyJSString();
}

// parameterized attributes
int AccessibilityUIElement::lineForIndex(int index)
{
    return -1;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::rangeForLine(int line)
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::rangeForPosition(int x, int y)
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::boundsForRange(unsigned location, unsigned length)
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::stringForRange(unsigned location, unsigned length)
{
    NSString *stringForRange = [m_element stringForRange:NSMakeRange(location, length)];
    return [stringForRange createJSStringRef];
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributedStringForRange(unsigned location, unsigned length)
{
    NSAttributedString *stringForRange = [m_element attributedStringForRange:NSMakeRange(location, length)];
    return [[stringForRange description] createJSStringRef];
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributedStringForElement()
{
    NSAttributedString *string = [m_element attributedStringForElement];
    if (![string isKindOfClass:[NSAttributedString class]])
        return nullptr;
    
    return [[string description] createJSStringRef];
}

bool AccessibilityUIElement::attributedStringRangeIsMisspelled(unsigned location, unsigned length)
{
    return false;
}

unsigned AccessibilityUIElement::uiElementCountForSearchPredicate(JSContextRef context, AccessibilityUIElement *startElement, bool isDirectionNext, JSValueRef searchKey, JSStringRef searchText, bool visibleOnly, bool immediateDescendantsOnly)
{
    return 0;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::uiElementForSearchPredicate(JSContextRef context, AccessibilityUIElement *startElement, bool isDirectionNext, JSValueRef searchKey, JSStringRef searchText, bool visibleOnly, bool immediateDescendantsOnly)
{
    NSDictionary *parameterizedAttribute = searchPredicateParameterizedAttributeForSearchCriteria(context, startElement, isDirectionNext, 5, searchKey, searchText, visibleOnly, immediateDescendantsOnly);
    id value = [m_element accessibilityFindMatchingObjects:parameterizedAttribute];
    if (![value isKindOfClass:[NSArray class]])
        return nullptr;
    for (id element in value) {
        if ([element isAccessibilityElement])
            return AccessibilityUIElement::create(element);
    }
    return AccessibilityUIElement::create([value firstObject]);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::selectTextWithCriteria(JSContextRef, JSStringRef ambiguityResolution, JSValueRef searchStrings, JSStringRef replacementString, JSStringRef activity)
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfColumnHeaders()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfRowHeaders()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfColumns()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfRows()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfVisibleCells()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributesOfHeader()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::traits()
{
    return concatenateAttributeAndValue(@"AXTraits", [NSString stringWithFormat:@"%qu", [m_element accessibilityTraits]]);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::identifier()
{
    return concatenateAttributeAndValue(@"AXIdentifier", [m_element accessibilityIdentifier]);
}

bool AccessibilityUIElement::hasContainedByFieldsetTrait()
{
    UIAccessibilityTraits traits = [m_element accessibilityTraits];
    return (traits & [m_element _axContainedByFieldsetTrait]) == [m_element _axContainedByFieldsetTrait];
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::fieldsetAncestorElement()
{
    id ancestorElement = [m_element _accessibilityFieldsetAncestor];
    if (ancestorElement)
        return AccessibilityUIElement::create(ancestorElement);
    
    return nullptr;
}

bool AccessibilityUIElement::isTextArea() const
{
    return ([m_element accessibilityTraits] & [m_element _axTextAreaTrait]) == [m_element _axTextAreaTrait];
}

bool AccessibilityUIElement::isSearchField() const
{
    return ([m_element accessibilityTraits] & [m_element _axSearchFieldTrait]) == [m_element _axSearchFieldTrait];
}

bool AccessibilityUIElement::isInDefinitionListDefinition() const
{
    return [m_element accessibilityIsInDescriptionListDefinition];
}

bool AccessibilityUIElement::isInDefinitionListTerm() const
{
    return [m_element accessibilityIsInDescriptionListTerm];
}
    
int AccessibilityUIElement::rowCount()
{
    return [m_element accessibilityRowCount];
}

int AccessibilityUIElement::columnCount()
{
    return [m_element accessibilityColumnCount];
}

bool AccessibilityUIElement::isInTableCell() const
{
    return [m_element _accessibilityIsInTableCell];
}

int AccessibilityUIElement::indexInTable()
{
    return -1;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::rowIndexRange()
{
    NSRange range = [m_element accessibilityRowRange];
    NSMutableString* rangeDescription = [NSMutableString stringWithFormat:@"{%lu, %lu}", (unsigned long)range.location, (unsigned long)range.length];
    return [rangeDescription createJSStringRef];
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::columnIndexRange()
{
    NSRange range = [m_element accessibilityColumnRange];
    NSMutableString* rangeDescription = [NSMutableString stringWithFormat:@"{%lu, %lu}", (unsigned long)range.location, (unsigned long)range.length];
    return [rangeDescription createJSStringRef];
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::cellForColumnAndRow(unsigned col, unsigned row)
{
    return AccessibilityUIElement::create([m_element accessibilityElementForRow:row andColumn:col]);
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::horizontalScrollbar() const
{
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::verticalScrollbar() const
{
    return nullptr;
}

void AccessibilityUIElement::scrollToMakeVisible()
{
}
    
void AccessibilityUIElement::scrollToGlobalPoint(int x, int y)
{
}
    
void AccessibilityUIElement::scrollToMakeVisibleWithSubFocus(int x, int y, int width, int height)
{
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::selectedTextRange()
{
    NSRange range = [m_element _accessibilitySelectedTextRange];
    NSMutableString *rangeDescription = [NSMutableString stringWithFormat:@"{%lu, %lu}", static_cast<unsigned long>(range.location), static_cast<unsigned long>(range.length)];
    return [rangeDescription createJSStringRef];
}

bool AccessibilityUIElement::setSelectedVisibleTextRange(AccessibilityTextMarkerRange*)
{
    return false;
}

bool AccessibilityUIElement::setSelectedTextRange(unsigned location, unsigned length)
{
    [m_element _accessibilitySetSelectedTextRange:NSMakeRange(location, length)];
    return true;
}

void AccessibilityUIElement::increment()
{
    [m_element accessibilityIncrement];
}

void AccessibilityUIElement::decrement()
{
    [m_element accessibilityDecrement];
}

void AccessibilityUIElement::showMenu()
{
}

void AccessibilityUIElement::press()
{
    [m_element _accessibilityActivate];
}
    
void AccessibilityUIElement::dismiss()
{
    [m_element accessibilityPerformEscape];
}

void AccessibilityUIElement::setSelectedChild(AccessibilityUIElement* element) const
{
}

void AccessibilityUIElement::setSelectedChildAtIndex(unsigned index) const
{
}

void AccessibilityUIElement::removeSelectionAtIndex(unsigned index) const
{
}

void AccessibilityUIElement::clearSelectedChildren() const
{
    // FIXME: implement
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::accessibilityValue() const
{
    // FIXME: implement
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::documentEncoding()
{
    return createEmptyJSString();
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::documentURI()
{
    return createEmptyJSString();
}

void AccessibilityUIElement::assistiveTechnologySimulatedFocus()
{
    [m_element accessibilityElementDidBecomeFocused];
}
    
bool AccessibilityUIElement::scrollPageUp()
{
    return [m_element accessibilityScroll:UIAccessibilityScrollDirectionUp];
}

bool AccessibilityUIElement::scrollPageDown()
{
    return [m_element accessibilityScroll:UIAccessibilityScrollDirectionDown];
}
bool AccessibilityUIElement::scrollPageLeft()
{
    return [m_element accessibilityScroll:UIAccessibilityScrollDirectionLeft];
}

bool AccessibilityUIElement::scrollPageRight()
{
    return [m_element accessibilityScroll:UIAccessibilityScrollDirectionRight];
}

void AccessibilityUIElement::increaseTextSelection()
{
    [m_element accessibilityModifySelection:WebCore::TextGranularity::CharacterGranularity increase:YES];
}

void AccessibilityUIElement::decreaseTextSelection()
{
    [m_element accessibilityModifySelection:WebCore::TextGranularity::CharacterGranularity increase:NO];
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::stringForSelection()
{
    NSString *stringForRange = [m_element selectionRangeString];
    return [stringForRange createJSStringRef];
}
    
int AccessibilityUIElement::elementTextPosition()
{
    NSRange range = [[m_element valueForKey:@"elementTextRange"] rangeValue];
    return range.location;
}

int AccessibilityUIElement::elementTextLength()
{
    NSRange range = [[m_element valueForKey:@"elementTextRange"] rangeValue];
    return range.length;    
}
    
JSRetainPtr<JSStringRef> AccessibilityUIElement::url()
{
    NSURL *url = [m_element accessibilityURL];
    return [[url absoluteString] createJSStringRef];
}

bool AccessibilityUIElement::addNotificationListener(JSValueRef functionCallback)
{
    if (!functionCallback)
        return false;
    
    // iOS programmers should not be adding more than one notification listener per element.
    // Other platforms may be different.
    if (m_notificationHandler)
        return false;
    m_notificationHandler = [[AccessibilityNotificationHandler alloc] init];
    [m_notificationHandler setPlatformElement:platformUIElement()];
    [m_notificationHandler setCallback:functionCallback];
    [m_notificationHandler startObserving];
    
    return true;
}

bool AccessibilityUIElement::removeNotificationListener()
{
    // iOS programmers should not be trying to remove a listener that's already removed.
    ASSERT(m_notificationHandler);
    
    [m_notificationHandler stopObserving];
    [m_notificationHandler release];
    m_notificationHandler = nil;
    
    return true;
}

bool AccessibilityUIElement::isFocusable() const
{
    return false;
}

bool AccessibilityUIElement::isSelectable() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isMultiSelectable() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isVisible() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isOffScreen() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isCollapsed() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isIgnored() const
{
    bool isAccessibilityElement = [m_element isAccessibilityElement];
    return !isAccessibilityElement;
}

bool AccessibilityUIElement::isSingleLine() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::isMultiLine() const
{
    // FIXME: implement
    return false;
}

bool AccessibilityUIElement::hasPopup() const
{
    return [m_element accessibilityHasPopup];
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::popupValue() const
{
    return [[m_element accessibilityPopupValue] createJSStringRef];
}

void AccessibilityUIElement::takeFocus()
{
    // FIXME: implement
}

void AccessibilityUIElement::takeSelection()
{
    // FIXME: implement
}

void AccessibilityUIElement::addSelection()
{
    // FIXME: implement
}

void AccessibilityUIElement::removeSelection()
{
    // FIXME: implement
}

// Text markers
RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::lineTextMarkerRangeForTextMarker(AccessibilityTextMarker* textMarker)
{
    id startTextMarker = [m_element lineStartMarkerForMarker:textMarker->platformTextMarker()];
    id endTextMarker = [m_element lineEndMarkerForMarker:textMarker->platformTextMarker()];
    NSArray *textMarkers = @[startTextMarker, endTextMarker];
    
    id textMarkerRange = [m_element textMarkerRangeForMarkers:textMarkers];
    return AccessibilityTextMarkerRange::create(textMarkerRange);
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::misspellingTextMarkerRange(AccessibilityTextMarkerRange* start, bool forward)
{
    id misspellingRange = [m_element misspellingTextMarkerRange:start->platformTextMarkerRange() forward:forward];
    return AccessibilityTextMarkerRange::create(misspellingRange);
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::textMarkerRangeForElement(AccessibilityUIElement* element)
{
    id textMarkerRange = [element->platformUIElement() textMarkerRange];
    return AccessibilityTextMarkerRange::create(textMarkerRange);
}

int AccessibilityUIElement::textMarkerRangeLength(AccessibilityTextMarkerRange* range)
{
    return [m_element lengthForTextMarkers:range->platformTextMarkerRange()];
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::previousTextMarker(AccessibilityTextMarker* textMarker)
{
    id previousMarker = [m_element previousMarkerForMarker:textMarker->platformTextMarker()];
    return AccessibilityTextMarker::create(previousMarker);
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::nextTextMarker(AccessibilityTextMarker* textMarker)
{
    id nextMarker = [m_element nextMarkerForMarker:textMarker->platformTextMarker()];
    return AccessibilityTextMarker::create(nextMarker);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::stringForTextMarkerRange(AccessibilityTextMarkerRange* markerRange)
{
    id textMarkers = markerRange->platformTextMarkerRange();
    if (![textMarkers isKindOfClass:[NSArray class]])
        return createEmptyJSString();
    return [[m_element stringForTextMarkers:textMarkers] createJSStringRef];
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::textMarkerRangeForMarkers(AccessibilityTextMarker* startMarker, AccessibilityTextMarker* endMarker)
{
    NSArray *textMarkers = @[startMarker->platformTextMarker(), endMarker->platformTextMarker()];
    id textMarkerRange = [m_element textMarkerRangeForMarkers:textMarkers];
    return AccessibilityTextMarkerRange::create(textMarkerRange);
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::startTextMarkerForTextMarkerRange(AccessibilityTextMarkerRange* range)
{
    id textMarkers = range->platformTextMarkerRange();
    id textMarker = [m_element startOrEndTextMarkerForTextMarkers:textMarkers isStart:YES];
    return AccessibilityTextMarker::create(textMarker);
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::endTextMarkerForTextMarkerRange(AccessibilityTextMarkerRange* range)
{
    id textMarkers = range->platformTextMarkerRange();
    id textMarker = [m_element startOrEndTextMarkerForTextMarkers:textMarkers isStart:NO];
    return AccessibilityTextMarker::create(textMarker);
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::endTextMarkerForBounds(int x, int y, int width, int height)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::startTextMarkerForBounds(int x, int y, int width, int height)
{
    return nullptr;
}
    
bool AccessibilityUIElement::replaceTextInRange(JSStringRef string, int location, int length)
{
    return [m_element accessibilityReplaceRange:NSMakeRange(location, length) withText:[NSString stringWithJSStringRef:string]];
}

bool AccessibilityUIElement::insertText(JSStringRef text)
{
    return [m_element accessibilityInsertText:[NSString stringWithJSStringRef:text]];
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::textMarkerForPoint(int x, int y)
{
    return nullptr;
}

RefPtr<AccessibilityUIElement> AccessibilityUIElement::accessibilityElementForTextMarker(AccessibilityTextMarker* marker)
{
    id obj = [m_element accessibilityObjectForTextMarker:marker->platformTextMarker()];
    if (obj)
        return AccessibilityUIElement::create(obj);
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributedStringForTextMarkerRange(AccessibilityTextMarkerRange* markerRange)
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::attributedStringForTextMarkerRangeWithOptions(AccessibilityTextMarkerRange* markerRange, bool)
{
    return nullptr;
}

bool AccessibilityUIElement::attributedStringForTextMarkerRangeContainsAttribute(JSStringRef attribute, AccessibilityTextMarkerRange* range)
{
    return false;
}

int AccessibilityUIElement::indexForTextMarker(AccessibilityTextMarker* marker)
{
    return [m_element positionForTextMarker:(__bridge id)marker->platformTextMarker()];
}

bool AccessibilityUIElement::isTextMarkerValid(AccessibilityTextMarker* textMarker)
{
    return false;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::textMarkerForIndex(int textIndex)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::startTextMarker()
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::endTextMarker()
{
    return nullptr;
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::leftWordTextMarkerRangeForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::rightWordTextMarkerRangeForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::previousWordStartTextMarkerForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::nextWordEndTextMarkerForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::paragraphTextMarkerRangeForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::nextParagraphEndTextMarkerForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::previousParagraphStartTextMarkerForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::sentenceTextMarkerRangeForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::nextSentenceEndTextMarkerForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}

RefPtr<AccessibilityTextMarker> AccessibilityUIElement::previousSentenceStartTextMarkerForTextMarker(AccessibilityTextMarker* textMarker)
{
    return nullptr;
}
    
RefPtr<AccessibilityTextMarkerRange> AccessibilityUIElement::textMarkerRangeMatchesTextNearMarkers(JSStringRef text, AccessibilityTextMarker* startMarker, AccessibilityTextMarker* endMarker)
{
    NSArray *textMarkers = nil;
    if (startMarker->platformTextMarker() && endMarker->platformTextMarker())
        textMarkers = @[startMarker->platformTextMarker(), endMarker->platformTextMarker()];
    id textMarkerRange = [m_element textMarkerRangeFromMarkers:textMarkers withText:[NSString stringWithJSStringRef:text]];
    return AccessibilityTextMarkerRange::create(textMarkerRange);
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::mathPostscriptsDescription() const
{
    return nullptr;
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::mathPrescriptsDescription() const
{
    return nullptr;
}

static void _CGPathEnumerationIteration(void *info, const CGPathElement *element)
{
    NSMutableString *result = (NSMutableString *)info;
    switch (element->type) {
    case kCGPathElementMoveToPoint:
        [result appendString:@"\tMove to point\n"];
        break;
    case kCGPathElementAddLineToPoint:
        [result appendString:@"\tLine to\n"];
        break;
    case kCGPathElementAddQuadCurveToPoint:
        [result appendString:@"\tQuad curve to\n"];
        break;
    case kCGPathElementAddCurveToPoint:
        [result appendString:@"\tCurve to\n"];
        break;
    case kCGPathElementCloseSubpath:
        [result appendString:@"\tClose\n"];
        break;
    }
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::pathDescription() const
{
    NSMutableString *result = [NSMutableString stringWithString:@"\nStart Path\n"];
    CGPathRef pathRef = [m_element _accessibilityPath];
    
    CGPathApply(pathRef, result, _CGPathEnumerationIteration);
    
    return [result createJSStringRef];
}

JSRetainPtr<JSStringRef> AccessibilityUIElement::supportedActions() const
{
    return nullptr;
}

} // namespace WTR

