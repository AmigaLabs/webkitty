/*
 * Copyright (C) 2020 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <wtf/OptionSet.h>
#include <wtf/Seconds.h>
#include <wtf/text/TextStream.h>

namespace WebCore {

using FramesPerSecond = unsigned;

enum class ThrottlingReason {
    VisuallyIdle                    = 1 << 0,
    OutsideViewport                 = 1 << 1,
    LowPowerMode                    = 1 << 2,
    NonInteractedCrossOriginFrame   = 1 << 3,
};

#if OS(MORPHOS)
constexpr const Seconds FullSpeedAnimationInterval { 30_ms };
constexpr const Seconds HalfSpeedThrottlingAnimationInterval { 60_ms };
constexpr const Seconds AggressiveThrottlingAnimationInterval { 10_s };
constexpr const FramesPerSecond FullSpeedFramesPerSecond = 30;
constexpr const FramesPerSecond HalfSpeedThrottlingFramesPerSecond = 15;
constexpr const FramesPerSecond ZeroFramesPerSecond = 0;
#else
// Allow a little more than 60fps to make sure we can at least hit that frame rate.
constexpr const Seconds FullSpeedAnimationInterval { 15_ms };
// Allow a little more than 30fps to make sure we can at least hit that frame rate.
constexpr const Seconds HalfSpeedThrottlingAnimationInterval { 30_ms };
constexpr const Seconds AggressiveThrottlingAnimationInterval { 10_s };

constexpr const FramesPerSecond FullSpeedFramesPerSecond = 60;
constexpr const FramesPerSecond HalfSpeedThrottlingFramesPerSecond = 30;
constexpr const FramesPerSecond ZeroFramesPerSecond = 0;
#endif

inline Seconds preferredFrameInterval(const OptionSet<ThrottlingReason>& reasons)
{
    // FIXME: handle ThrottlingReason::VisuallyIdle
    if (reasons.contains(ThrottlingReason::OutsideViewport))
        return AggressiveThrottlingAnimationInterval;
    
    if (reasons.containsAny({ ThrottlingReason::LowPowerMode, ThrottlingReason::NonInteractedCrossOriginFrame }))
        return HalfSpeedThrottlingAnimationInterval;

    return FullSpeedAnimationInterval;
}

inline FramesPerSecond preferredFramesPerSecond(Seconds preferredFrameInterval)
{
    if (preferredFrameInterval == FullSpeedAnimationInterval)
        return FullSpeedFramesPerSecond;

    if (preferredFrameInterval == HalfSpeedThrottlingAnimationInterval)
        return HalfSpeedThrottlingFramesPerSecond;

    ASSERT_NOT_REACHED();
    return ZeroFramesPerSecond;
}

inline TextStream& operator<<(TextStream& ts, const OptionSet<ThrottlingReason>& reasons)
{
    bool didAppend = false;

    for (auto reason : reasons) {
        if (didAppend)
            ts << "|";
        switch (reason) {
        case ThrottlingReason::VisuallyIdle:
            ts << "VisuallyIdle";
            break;
        case ThrottlingReason::OutsideViewport:
            ts << "OutsideViewport";
            break;
        case ThrottlingReason::LowPowerMode:
            ts << "LowPowerMode";
            break;
        case ThrottlingReason::NonInteractedCrossOriginFrame:
            ts << "NonInteractiveCrossOriginFrame";
            break;
        }
        didAppend = true;
    }

    if (reasons.isEmpty())
        ts << "[Unthrottled]";
    return ts;
}

}
