#pragma once
#include <wtf/RefPtr.h>
#include <wtf/HashSet.h>
#include <wtf/Vector.h>
#include <WebCore/PageIdentifier.h>
#include <WebCore/Color.h>
#include <WebCore/GraphicsTypes.h>
#include <WebCore/FindOptions.h>
#include "WebViewDelegate.h"
#include "WebFrame.h"
#include <intuition/classusr.h>

namespace WebCore {
	class Page;
	class Frame;
	class FrameView;
	class IntRect;
	class KeyboardEvent;
	class ResourceError;
	class ContextMenuItem;
	class CertificateInfo;
	class AutofillElements;
	class HTMLInputElement;
	class HistoryItem;
};

struct RastPort;
struct IntuiMessage;

namespace WebKit {

class WebPage;
class WebPageGroup;
class WebFrame;
class WebViewDrawContext;
class WebChromeClient;
class WebPageCreationParameters;
class WebDocumentLoader;
class BackForwardClientMorphOS;

WebCore::Page* core(WebPage *webView);
WebPage *kit(WebCore::Page* page);

WebCore::Frame& mainframe(WebCore::Page& page);
const WebCore::Frame& mainframe(const WebCore::Page& page);

class WebPage : public WebViewDelegate, public WTF::RefCounted<WebPage>
{
friend class WebChromeClient;
public:
    static Ref<WebPage> create(WebCore::PageIdentifier, WebPageCreationParameters&&);

    virtual ~WebPage();

	WebCore::Page *corePage();
	const WebCore::Page *corePage() const;
	static WebPage *fromCorePage(WebCore::Page *corePage);

    WebCore::PageIdentifier pageID() const { return m_pageID; }
    PAL::SessionID sessionID() const;

	void load(const char *url);
	void loadData(const char *data, size_t length, const char *url);
	void reload();
	void stop();
	
	WebCore::CertificateInfo getCertificate(void);
	
	void run(const char *js);
	void *evaluate(const char *js, WTF::Function<void *(const char *)>&& response);
	
	void *getInnerHTML(WTF::Function<void *(const char *)>&& cb);
	void setInnerHTML(const char *html);

	bool goBack();
	bool goForward();
	bool canGoBack();
	bool canGoForward();
	void goToItem(WebCore::HistoryItem& item);

	void willBeDisposed();

	bool javaScriptEnabled() const;
	void setJavaScriptEnabled(bool enabled);
	
	bool adBlockingEnabled() const;
	void setAdBlockingEnabled(bool enabled);
	
	bool thirdPartyCookiesAllowed() const;
	void setThirdPartyCookiesAllowed(bool blocked);

	void setVisibleSize(const int width, const int height);
	void setScroll(const int x, const int y);
	void draw(struct RastPort *rp, const int x, const int y, const int width, const int height, bool updateMode);
	bool handleIntuiMessage(IntuiMessage *imsg, const int mouseX, const int mouseY, bool mouseInside, bool isDefaultHandler);
	bool checkDownloadable(IntuiMessage *imsg, const int mouseX, const int mouseY, WTF::URL &outURL);
	bool handleMUIKey(int muikey, bool isDefaultHandler);

	void onContextMenuItemSelected(ULONG action, const char *title);

    void addResourceRequest(unsigned long, const WebCore::ResourceRequest&);
    void removeResourceRequest(unsigned long);

    void didStartPageTransition();
    void didCompletePageTransition();
    void didCommitLoad(WebFrame& frame);
	void didFinishDocumentLoad(WebFrame& frame);
	void didFinishLoad(WebFrame& frame);
	void didFailLoad(const WebCore::ResourceError& error);

    Ref<WebCore::DocumentLoader> createDocumentLoader(WebCore::Frame&, const WebCore::ResourceRequest&, const WebCore::SubstituteData&);
    void updateCachedDocumentLoader(WebDocumentLoader&, WebCore::Frame&);

    void scalePage(double scale, const WebCore::IntPoint& origin);
    double pageScaleFactor() const;
    double totalScaleFactor() const;
    double viewScaleFactor() const;

    float pageZoomFactor() const;
    float textZoomFactor() const;
    void setPageAndTextZoomFactors(float pageZoomFactor, float textZoomFactor);

    bool mainFrameIsScrollable() const { return m_mainFrameIsScrollable; }

    void setAlwaysShowsHorizontalScroller(bool);
    void setAlwaysShowsVerticalScroller(bool);

    bool alwaysShowsHorizontalScroller() const { return m_alwaysShowsHorizontalScroller; };
    bool alwaysShowsVerticalScroller() const { return m_alwaysShowsVerticalScroller; };

	bool handleEditingKeyboardEvent(WebCore::KeyboardEvent& event);

    const Optional<WebCore::Color>& backgroundColor() const { return m_backgroundColor; }
	
    void setInterpolationQuality(WebCore::InterpolationQuality quality) { m_interpolation = quality; }
    WebCore::InterpolationQuality interpolationQuality() const { return m_interpolation; }

    WebCore::IntSize size() const;
    WebCore::IntRect bounds() const { return WebCore::IntRect(WebCore::IntPoint(), size()); }

    WebFrame& topLevelFrame() const { return m_mainFrame; }

    WebCore::Frame* mainFrame() const; // May return nullptr.
    WebCore::FrameView* mainFrameView() const; // May return nullptr.

	WTF::RefPtr<WebKit::BackForwardClientMorphOS> backForwardClient();

    void goActive();
    void goInactive();
    void goVisible();
    bool isVisible() const { return m_isVisible; }
    void goHidden();
	
	void setLowPowerMode(bool lowPowerMode);

	void startLiveResize();
	void endLiveResize();
	
    void setFocusedElement(WebCore::Element *);
	
	void startedEditingElement(WebCore::HTMLInputElement *);
	bool hasAutofillElements();
	void clearAutofillElements();
	void setAutofillElements(const WTF::String &login, const WTF::String &password);
	bool getAutofillElements(WTF::String &outlogin, WTF::String &outPassword);

	void setCursor(int);

	bool drawRect(const int x, const int y, const int width, const int height, struct RastPort *rp);
	void invalidate();

	bool search(const WTF::String &string, WebCore::FindOptions &options, bool& outWrapped);
	
	void loadUserStyleSheet(const WTF::String &path);
	
	bool allowsScrolling();
	void setAllowsScrolling(bool allows);

	enum class ContextMenuHandling // keep in sync with WkSettings!!
	{
		Default,
		Override,
		OverrideWithShift,
		OverrideWithAlt,
		OverrideWithControl,
	};
	
	void setContextMenuHandling(ContextMenuHandling handling) { m_cmHandling = handling; }
	ContextMenuHandling contextMenuHandling() const { return m_cmHandling; }

	// WkHitTest support...
	WebCore::Frame *fromHitTest(WebCore::HitTestResult &hitTest) const;
	bool hitTestImageToClipboard(WebCore::HitTestResult &hitTest) const;
	bool hitTestSaveImageToFile(WebCore::HitTestResult &hitTest, const WTF::String &path) const;
	void hitTestReplaceSelectedTextWidth(WebCore::HitTestResult &hitTest, const WTF::String &text) const;
	void hitTestCopySelectedText(WebCore::HitTestResult &hitTest) const;
	void hitTestCutSelectedText(WebCore::HitTestResult &hitTest) const;
	void hitTestPaste(WebCore::HitTestResult &hitTest) const;
	void hitTestSelectAll(WebCore::HitTestResult &hitTest) const;

	void startDownload(const WTF::URL &url);

protected:
	WebPage(WebCore::PageIdentifier, WebPageCreationParameters&&);

	// WebChrome methods
    void repaint(const WebCore::IntRect&);
    void internalScroll(int scrollX, int scrollY);
	void scrollBy(const int xDelta, const int yDelta, WebCore::Frame *inFrame = nullptr);
	void wheelScrollOrZoomBy(const int xDelta, const int yDelta, ULONG qualifiers, WebCore::Frame *inFrame = nullptr);
    void frameSizeChanged(WebCore::Frame& frame, int width, int height);

    void closeWindow();
    void closeWindowSoon();
    void closeWindowTimerFired();

    bool transparent() const { return m_transparent; }
    bool usesLayeredWindow() const { return m_usesLayeredWindow; }

private:
	Ref<WebFrame> m_mainFrame;
	std::unique_ptr<WebCore::Page> m_page;
	RefPtr<WebPageGroup> m_webPageGroup;
	WebViewDrawContext  *m_drawContext { nullptr };
    WebCore::PageIdentifier m_pageID;
    WebCore::AutofillElements *m_autofillElements { nullptr };
    WebCore::InterpolationQuality m_interpolation = WebCore::InterpolationQuality::Default;
    WTF::HashSet<unsigned long> m_trackedNetworkResourceRequestIdentifiers;
    uint64_t m_pendingNavigationID { 0 };
	uint32_t m_lastQualifier { 0 };
	int  m_clickCount { 0 };
	int  m_cursor { 0 };
	bool m_transparent { false };
	bool m_usesLayeredWindow { false };
    bool m_mainFrameProgressCompleted { false };
    bool m_alwaysShowsHorizontalScroller { false };
    bool m_alwaysShowsVerticalScroller { false };
    bool m_mainFrameIsScrollable { true };
    bool m_trackMouse { false };
    bool m_ignoreScroll { false };
    bool m_orphaned { false };
    bool m_adBlocking { true };
    bool m_justWentActive { false };
    bool m_isActive { false };
    bool m_isVisible { false };
    WebCore::Element *m_focusedElement { nullptr };
    ContextMenuHandling m_cmHandling { ContextMenuHandling::Default };
    Optional<WebCore::Color> m_backgroundColor { WebCore::Color::white };
    WTF::URL m_hoveredURL;
};

}
