/*
 * Copyright (C) 2021 Apple Inc. All rights reserved.
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

#include <wtf/EnumTraits.h>

namespace WebCore {

enum class ModalContainerControlType : uint8_t {
    Neutral = 1 << 0,
    Positive = 1 << 1,
    Negative = 1 << 2,
    Other = 1 << 3,
};

enum class ModalContainerDecision : uint8_t {
    Show,
    HideAndIgnore,
    HideAndAllow,
    HideAndDisallow,
};

} // namespace WebCore

namespace WTF {

template<> struct EnumTraits<WebCore::ModalContainerControlType> {
    using values = EnumValues<
        WebCore::ModalContainerControlType,
        WebCore::ModalContainerControlType::Neutral,
        WebCore::ModalContainerControlType::Positive,
        WebCore::ModalContainerControlType::Negative,
        WebCore::ModalContainerControlType::Other
    >;
};

template<> struct EnumTraits<WebCore::ModalContainerDecision> {
    using values = EnumValues<
        WebCore::ModalContainerDecision,
        WebCore::ModalContainerDecision::Show,
        WebCore::ModalContainerDecision::HideAndIgnore,
        WebCore::ModalContainerDecision::HideAndAllow,
        WebCore::ModalContainerDecision::HideAndDisallow
    >;
};

} // namespace WTF
