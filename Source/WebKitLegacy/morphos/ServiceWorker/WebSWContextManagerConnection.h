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

#pragma once
#include "WebKit.h"

#if ENABLE(SERVICE_WORKER)

#include <WebCore/SWContextManager.h>
#include <WebCore/ServiceWorkerClientData.h>
#include <WebCore/ServiceWorkerTypes.h>
#include <wtf/URLHash.h>

namespace WebCore {
struct FetchOptions;
class ResourceRequest;
struct ServiceWorkerContextData;
enum class WorkerThreadMode : bool;
}

namespace WebKit {

class RemoteWorkerFrameLoaderClient;
class WebUserContentController;
class WebSWServerToContextConnection;
struct RemoteWorkerInitializationData;

class WebSWContextManagerConnection final : public WebCore::SWContextManager::Connection {
public:
    WebSWContextManagerConnection(WebCore::RegistrableDomain&&, std::optional<WebCore::ScriptExecutionContextIdentifier> serviceWorkerPageIdentifier, WebCore::PageIdentifier);
    ~WebSWContextManagerConnection();

    WebCore::PageIdentifier pageIdentifier() const final { return m_pageID; }

public:
    // WebCore::SWContextManager::Connection.
    void establishConnection(CompletionHandler<void()>&&) final;
    void postMessageToServiceWorkerClient(const WebCore::ScriptExecutionContextIdentifier& destinationIdentifier, const WebCore::MessageWithMessagePorts&, WebCore::ServiceWorkerIdentifier sourceIdentifier, const String& sourceOrigin) final;
    void didFinishInstall(std::optional<WebCore::ServiceWorkerJobDataIdentifier>, WebCore::ServiceWorkerIdentifier, bool wasSuccessful) final;
    void didFinishActivation(WebCore::ServiceWorkerIdentifier) final;
    void setServiceWorkerHasPendingEvents(WebCore::ServiceWorkerIdentifier, bool) final;
    void workerTerminated(WebCore::ServiceWorkerIdentifier) final;
    void findClientByVisibleIdentifier(WebCore::ServiceWorkerIdentifier, const String&, FindClientByIdentifierCallback&&) final;
    void matchAll(WebCore::ServiceWorkerIdentifier, const WebCore::ServiceWorkerClientQueryOptions&, WebCore::ServiceWorkerClientsMatchAllCallback&&) final;
    void claim(WebCore::ServiceWorkerIdentifier, CompletionHandler<void(WebCore::ExceptionOr<void>&&)>&&) final;
    void skipWaiting(WebCore::ServiceWorkerIdentifier, CompletionHandler<void()>&&) final;
    void setScriptResource(WebCore::ServiceWorkerIdentifier, const URL&, const WebCore::ServiceWorkerContextData::ImportedScript&) final;
    bool isThrottleable() const final;
    void didFailHeartBeatCheck(WebCore::ServiceWorkerIdentifier) final;

    // IPC messages.
    void serviceWorkerStarted(std::optional<WebCore::ServiceWorkerJobDataIdentifier>, WebCore::ServiceWorkerIdentifier, bool doesHandleFetch) final;
    void serviceWorkerFailedToStart(std::optional<WebCore::ServiceWorkerJobDataIdentifier>, WebCore::ServiceWorkerIdentifier, const String& exceptionMessage) final;
    void installServiceWorker(WebCore::ServiceWorkerContextData&&, WebCore::ServiceWorkerData&&, String&& userAgent, WebCore::WorkerThreadMode);
    void updateAppInitiatedValue(WebCore::ServiceWorkerIdentifier, WebCore::LastNavigationWasAppInitiated);
    void startFetch(WebCore::SWServerConnectionIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier, WebCore::ResourceRequest&&, WebCore::FetchOptions&&, String&& referrer, bool isServiceWorkerNavigationPreloadEnabled, String&& clientIdentifier, String&& resultingClientIdentifier);
    void cancelFetch(WebCore::SWServerConnectionIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier);
    void continueDidReceiveFetchResponse(WebCore::SWServerConnectionIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier);
    void postMessageToServiceWorker(WebCore::ServiceWorkerIdentifier destinationIdentifier, WebCore::MessageWithMessagePorts&&, WebCore::ServiceWorkerOrClientData&& sourceData);
    void fireInstallEvent(WebCore::ServiceWorkerIdentifier);
    void fireActivateEvent(WebCore::ServiceWorkerIdentifier);
    void firePushEvent(WebCore::ServiceWorkerIdentifier, CompletionHandler<void(bool)>&&);
    void terminateWorker(WebCore::ServiceWorkerIdentifier);
    void matchAllCompleted(uint64_t matchAllRequestIdentifier, Vector<WebCore::ServiceWorkerClientData>&&);
    void setUserAgent(String&& userAgent);
    void close();
    void setThrottleState(bool isThrottleable);
    void convertFetchToDownload(WebCore::SWServerConnectionIdentifier, WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier);
    void cancelFetchDownload(WebCore::ServiceWorkerIdentifier, WebCore::FetchIdentifier);

    WebCore::RegistrableDomain m_registrableDomain;
    std::optional<WebCore::ScriptExecutionContextIdentifier> m_serviceWorkerPageIdentifier;
    WebCore::PageIdentifier m_pageID;

//    HashSet<std::unique_ptr<RemoteWorkerFrameLoaderClient>> m_loaders;
    HashMap<uint64_t, WebCore::ServiceWorkerClientsMatchAllCallback> m_matchAllRequests;
    uint64_t m_previousRequestIdentifier { 0 };
    String m_userAgent;
    bool m_isThrottleable { true };
//    Ref<WebUserContentController> m_userContentController;

    std::unique_ptr<WebSWServerToContextConnection> m_swContextConnection;
};

} // namespace WebKit

#endif // ENABLE(SERVICE_WORKER)
