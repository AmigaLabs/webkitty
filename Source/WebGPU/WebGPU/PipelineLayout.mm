/*
 * Copyright (c) 2021-2022 Apple Inc. All rights reserved.
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

#import "config.h"
#import "PipelineLayout.h"

#import "BindGroupLayout.h"
#import "Device.h"

namespace WebGPU {

RefPtr<PipelineLayout> Device::createPipelineLayout(const WGPUPipelineLayoutDescriptor* descriptor)
{
    if (descriptor->nextInChain)
        return nullptr;

    Vector<Ref<BindGroupLayout>> bindGroupLayouts;
    bindGroupLayouts.reserveInitialCapacity(descriptor->bindGroupLayoutCount);
    for (uint32_t i = 0; i < descriptor->bindGroupLayoutCount; ++i) {
        const auto* bindGroupLayout = descriptor->bindGroupLayouts[i];
        bindGroupLayouts.uncheckedAppend(bindGroupLayout->bindGroupLayout);
    }
    return PipelineLayout::create(WTFMove(bindGroupLayouts));
}

PipelineLayout::PipelineLayout(Vector<Ref<BindGroupLayout>>&& bindGroupLayouts)
    : m_bindGroupLayouts(WTFMove(bindGroupLayouts))
{
}

PipelineLayout::~PipelineLayout() = default;

void PipelineLayout::setLabel(const char*)
{
    // There is no Metal object that represents a pipeline layout.
}

bool PipelineLayout::operator==(const PipelineLayout& other) const
{
    UNUSED_PARAM(other);
    // FIXME: Implement this
    return false;
}

bool PipelineLayout::operator!=(const PipelineLayout& other) const
{
    return !(*this == other);
}

}

void wgpuPipelineLayoutRelease(WGPUPipelineLayout pipelineLayout)
{
    delete pipelineLayout;
}

void wgpuPipelineLayoutSetLabel(WGPUPipelineLayout pipelineLayout, const char* label)
{
    pipelineLayout->pipelineLayout->setLabel(label);
}
