/*
 * Copyright (C) 2018-2020 Apple Inc. All rights reserved.
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
#import "MediaUtilities.h"

namespace WebKit {

_WKMediaCaptureState toWKMediaCaptureState(WebCore::MediaProducer::MediaStateFlags state)
{
    _WKMediaCaptureState mediaCaptureState = _WKMediaCaptureStateNone;
    if (state & WebCore::MediaProducer::HasActiveAudioCaptureDevice)
        mediaCaptureState |= _WKMediaCaptureStateActiveMicrophone;
    if (state & WebCore::MediaProducer::HasActiveVideoCaptureDevice)
        mediaCaptureState |= _WKMediaCaptureStateActiveCamera;
    if (state & WebCore::MediaProducer::HasMutedAudioCaptureDevice)
        mediaCaptureState |= _WKMediaCaptureStateMutedMicrophone;
    if (state & WebCore::MediaProducer::HasMutedVideoCaptureDevice)
        mediaCaptureState |= _WKMediaCaptureStateMutedCamera;

    return mediaCaptureState;
}

_WKMediaMutedState toWKMediaMutedState(WebCore::MediaProducer::MutedStateFlags state)
{
    _WKMediaMutedState mediaMutedState = _WKMediaNoneMuted;
    if (state & WebCore::MediaProducer::NoneMuted)
        mediaMutedState |= _WKMediaNoneMuted;
    if (state & WebCore::MediaProducer::AudioIsMuted)
        mediaMutedState |= _WKMediaAudioMuted;
    if (state & WebCore::MediaProducer::AudioAndVideoCaptureIsMuted)
        mediaMutedState |= _WKMediaCaptureDevicesMuted;
    if (state & WebCore::MediaProducer::ScreenCaptureIsMuted)
        mediaMutedState |= _WKMediaScreenCaptureMuted;
    return mediaMutedState;
}

} // namespace WebKit
