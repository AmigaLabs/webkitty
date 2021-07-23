/*
 * Copyright (C) 2020 Jacek Piszczek
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

#include "config.h"

#if ENABLE(WEB_AUDIO)
#include "AudioDestinationMorphOS.h"
#include "AudioChannel.h"
#include "AudioSourceProvider.h"
#include "NotImplemented.h"
#include "AudioUtilities.h"
#include <proto/exec.h>

namespace WebCore {

static const unsigned framesToPull = 128; // render quantum 

float AudioDestination::hardwareSampleRate()
{
	return 44100.f;
}

unsigned long AudioDestination::AudioDestination::maxChannelCount()
{
	return 0; // stereo
}

Ref<AudioDestination> AudioDestination::create(AudioIOCallback&callback, const String& inputDeviceId, unsigned numberOfInputChannels, unsigned numberOfOutputChannels, float sampleRate)
{
    return adoptRef(*new AudioDestinationMorphOS(callback, sampleRate));
}

AudioDestinationMorphOS::AudioDestinationMorphOS(AudioIOCallback&callback, float sampleRate)
	: AudioDestination(callback)
	, m_renderBus(AudioBus::create(2, framesToPull, true))
	, m_output(*this)
	, m_sampleRate(sampleRate)
	, m_isPlaying(false)
{
	m_renderBus->setSampleRate(44100);
}

AudioDestinationMorphOS::~AudioDestinationMorphOS()
{

}

void AudioDestinationMorphOS::start(Function<void(Function<void()>&&)>&& dispatchToRenderThread, CompletionHandler<void(bool)>&&completionHandler)
{
    {
        auto locker = holdLock(m_dispatchToRenderThreadLock);
        m_dispatchToRenderThread = WTFMove(dispatchToRenderThread);
    }

    startRendering(WTFMove(completionHandler));
}

void AudioDestinationMorphOS::startRendering(CompletionHandler<void(bool)>&& completionHandler)
{
    ASSERT(isMainThread());
    auto success = m_output.start();
    if (success)
        setIsPlaying(true);

    callOnMainThread([completionHandler = WTFMove(completionHandler), success]() mutable {
        completionHandler(success);
    });
}

void AudioDestinationMorphOS::stop(CompletionHandler<void(bool)>&&completionHandler)
{
dprintf("%s\n", __PRETTY_FUNCTION__);
    stopRendering(WTFMove(completionHandler));
    {
        auto locker = holdLock(m_dispatchToRenderThreadLock);
        m_dispatchToRenderThread = nullptr;
    }
}

void AudioDestinationMorphOS::stopRendering(CompletionHandler<void(bool)>&& completionHandler)
{
    ASSERT(isMainThread());
    m_output.stop();
	setIsPlaying(false);

    callOnMainThread([completionHandler = WTFMove(completionHandler)]() mutable {
        completionHandler(true);
    });
}

unsigned AudioDestinationMorphOS::framesPerBuffer() const
{
	return m_renderBus->length();
}

void AudioDestinationMorphOS::render(int16_t *samplesStereo, size_t count)
{
	auto locker = tryHoldLock(m_dispatchToRenderThreadLock);

	if (!locker || !m_dispatchToRenderThread)
		return;

	m_dispatchToRenderThread([count = count, samplesStereo = samplesStereo, this, protectedThis = makeRef(*this)] {
		const auto length = m_renderBus->channel(0)->length();
		int16_t *out = samplesStereo;
		for (size_t i = 0; i < count; i+= length)
		{

			m_outputTimestamp = {
				Seconds { m_sampleTime / double(sampleRate()) },
				MonotonicTime::now()
			};
			
			m_sampleTime += length;
//dprintf("render length %d sampleTime %f count %d, time %f\n", length, float(m_sampleTime), count, float(m_sampleTime / double(sampleRate())));
			callRenderCallback(nullptr, m_renderBus.get(), length, m_outputTimestamp);

			AudioChannel *channelA = m_renderBus->channel(0);
			AudioChannel *channelB = m_renderBus->channel(1);

			if (channelA->isSilent() && channelB->isSilent())
			{
				memset(samplesStereo, 0, count * 4);
//dprintf("silence\n");
			}
			else
			{
				auto dataA = channelA->data();
				auto dataB = channelB->data();
				static constexpr float fmultiplier = 32767;
				for (size_t sample = 0; sample < length; sample ++)
				{
					*out++ = int16_t(dataA[sample] * fmultiplier);
					*out++ = int16_t(dataB[sample] * fmultiplier);
//if (sample % 16 == 0) dprintf("@%d: %f %f > %d %d\n", sample, dataA[sample], dataB[sample], int16_t(dataA[sample] * fmultiplier), int16_t(dataB[sample] * fmultiplier));
				}
			}
		};
	});
}


}

#endif
