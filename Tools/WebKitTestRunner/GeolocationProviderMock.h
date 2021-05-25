/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
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

#ifndef GeolocationProviderMock_h
#define GeolocationProviderMock_h

#include <WebKit/WKRetainPtr.h>
#include <wtf/FastMalloc.h>

namespace WTR {

class GeolocationProviderMock {
    WTF_MAKE_FAST_ALLOCATED;
public:
    GeolocationProviderMock(WKContextRef);
    ~GeolocationProviderMock();

    void setPosition(double latitude, double longitude, double accuracy, Optional<double> altitude, Optional<double> altitudeAccuracy, Optional<double> heading, Optional<double> speed, Optional<double> floorLevel);
    void setPositionUnavailableError(WKStringRef errorMessage);

    void startUpdating(WKGeolocationManagerRef);
    void stopUpdating(WKGeolocationManagerRef);

    bool isActive() const { return m_isActive; }

private:
    void sendPositionIfNeeded();
    void sendErrorIfNeeded();

    WKRetainPtr<WKContextRef> m_context;
    WKGeolocationManagerRef m_geolocationManager;
    bool m_isActive { false };

    WKRetainPtr<WKGeolocationPositionRef> m_position;

    bool m_hasError { false };
    WKRetainPtr<WKStringRef> m_errorMessage;
};

} // namespace WTR

#endif // GeolocationProviderMock_h
