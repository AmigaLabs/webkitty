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

#if ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)

#include "CaptureDeviceManager.h"
#include "GenericTaskQueue.h"
#include <wtf/Forward.h>
#include <wtf/HashSet.h>
#include <wtf/Lock.h>
#include <wtf/RetainPtr.h>

OBJC_CLASS AVAudioSession;
OBJC_CLASS WebAVAudioSessionAvailableInputsListener;

namespace WebCore {

class AVAudioSessionCaptureDevice;
class CaptureDevice;

class AVAudioSessionCaptureDeviceManager final : public CaptureDeviceManager {
    friend class NeverDestroyed<AVAudioSessionCaptureDeviceManager>;
public:
    static AVAudioSessionCaptureDeviceManager& singleton();

    const Vector<CaptureDevice>& captureDevices() final;
    void getCaptureDevices(CompletionHandler<void(Vector<CaptureDevice>&&)>&&) final;
    const Vector<CaptureDevice>& speakerDevices() const { return m_speakerDevices; }
    Optional<CaptureDevice> captureDeviceWithPersistentID(CaptureDevice::DeviceType, const String&);

    Optional<AVAudioSessionCaptureDevice> audioSessionDeviceWithUID(const String&);
    
    void scheduleUpdateCaptureDevices();

    void enableAllDevicesQuery();
    void disableAllDevicesQuery();

private:
    AVAudioSessionCaptureDeviceManager();
    ~AVAudioSessionCaptureDeviceManager();

    void createAudioSession();
    void activateAudioSession();
    void refreshAudioCaptureDevices();
    Vector<AVAudioSessionCaptureDevice> retrieveAudioSessionCaptureDevices() const;
    void setAudioCaptureDevices(Vector<AVAudioSessionCaptureDevice>&&);

    enum class AudioSessionState { NotNeeded, Inactive, Active };

    Optional<Vector<CaptureDevice>> m_devices;
    Vector<CaptureDevice> m_speakerDevices;
    Optional<Vector<AVAudioSessionCaptureDevice>> m_audioSessionCaptureDevices;
    RetainPtr<WebAVAudioSessionAvailableInputsListener> m_listener;
    RetainPtr<AVAudioSession> m_audioSession;
    GenericTaskQueue<Timer> m_updateDeviceStateQueue;
    dispatch_queue_t m_dispatchQueue { nullptr };
    Lock m_lock;
    AudioSessionState m_audioSessionState { AudioSessionState::NotNeeded };
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && PLATFORM(IOS_FAMILY)
