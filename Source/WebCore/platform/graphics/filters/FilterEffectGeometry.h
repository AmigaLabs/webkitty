/*
 * Copyright (C) 2021 Apple Inc.  All rights reserved.
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

#include "FloatRect.h"
#include <wtf/OptionSet.h>
#include <wtf/Ref.h>

#if OS(AMIGAOS)
#include <wtf/EnumTraits.h>
#endif

namespace WebCore {

class FilterEffect;

class FilterEffectGeometry {
public:
    enum class Flags {
        HasX      = 1 << 0,
        HasY      = 1 << 1,
        HasWidth  = 1 << 2,
        HasHeight = 1 << 3
    };

    FilterEffectGeometry() = default;

    FilterEffectGeometry(const FloatRect& boundaries, OptionSet<Flags> flags)
        : m_boundaries(boundaries)
        , m_flags(flags)
    {
    }

    std::optional<float> x() const
    {
        if (m_flags.contains(Flags::HasX))
            return m_boundaries.x();
        return std::nullopt;
    }

    std::optional<float> y() const
    {
        if (m_flags.contains(Flags::HasY))
            return m_boundaries.y();
        return std::nullopt;
    }

    std::optional<float> width() const
    {
        if (m_flags.contains(Flags::HasWidth))
            return m_boundaries.width();
        return std::nullopt;
    }

    std::optional<float> height() const
    {
        if (m_flags.contains(Flags::HasHeight))
            return m_boundaries.height();
        return std::nullopt;
    }

    template<class Encoder> void encode(Encoder&) const;
    template<class Decoder> static std::optional<FilterEffectGeometry> decode(Decoder&);

private:
    FloatRect m_boundaries;
    OptionSet<Flags> m_flags;
};

using FilterEffectGeometryMap = HashMap<Ref<FilterEffect>, FilterEffectGeometry>;

template<class Encoder>
void FilterEffectGeometry::encode(Encoder& encoder) const
{
    encoder << m_boundaries;
    encoder << m_flags;
}

template<class Decoder>
std::optional<FilterEffectGeometry> FilterEffectGeometry::decode(Decoder& decoder)
{
    std::optional<FloatRect> boundaries;
    decoder >> boundaries;
    if (!boundaries)
        return std::nullopt;

    std::optional<OptionSet<Flags>> flags;
    decoder >> flags;
    if (!flags)
        return std::nullopt;

    return FilterEffectGeometry(*boundaries, *flags);
}

} // namespace WebCore

namespace WTF {

template<> struct EnumTraits<WebCore::FilterEffectGeometry::Flags> {
    using values = EnumValues<
        WebCore::FilterEffectGeometry::Flags,

        WebCore::FilterEffectGeometry::Flags::HasX,
        WebCore::FilterEffectGeometry::Flags::HasY,
        WebCore::FilterEffectGeometry::Flags::HasWidth,
        WebCore::FilterEffectGeometry::Flags::HasHeight
    >;
};

} // namespace WTF
