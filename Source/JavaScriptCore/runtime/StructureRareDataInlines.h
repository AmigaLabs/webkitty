/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
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

#include "JSImmutableButterfly.h"
#include "JSPropertyNameEnumerator.h"
#include "JSString.h"
#include "StructureRareData.h"

namespace JSC {

// FIXME: Use ObjectPropertyConditionSet instead.
// https://bugs.webkit.org/show_bug.cgi?id=216112
struct SpecialPropertyCacheEntry {
    WTF_MAKE_STRUCT_FAST_ALLOCATED;
    ~SpecialPropertyCacheEntry();
    Bag<CachedSpecialPropertyAdaptiveStructureWatchpoint> m_missWatchpoints;
    std::unique_ptr<CachedSpecialPropertyAdaptiveInferredPropertyValueWatchpoint> m_equivalenceWatchpoint;
    WriteBarrier<Unknown> m_value;
};

struct SpecialPropertyCache {
    WTF_MAKE_STRUCT_FAST_ALLOCATED;
    SpecialPropertyCacheEntry m_cache[numberOfCachedSpecialPropertyKeys];
};

inline void StructureRareData::setPreviousID(VM& vm, Structure* structure)
{
    m_previous.set(vm, this, structure);
}

inline void StructureRareData::clearPreviousID()
{
    m_previous.clear();
}

inline JSValue StructureRareData::cachedSpecialProperty(CachedSpecialPropertyKey key) const
{
    auto* cache = m_specialPropertyCache.get();
    if (!cache)
        return JSValue();
    JSValue value = cache->m_cache[static_cast<unsigned>(key)].m_value.get();
    if (value == JSCell::seenMultipleCalleeObjects())
        return JSValue();
#if ASSERT_ENABLED
    if (value && value.isCell())
        validateCell(value.asCell());
#endif
    return value;
}

inline JSPropertyNameEnumerator* StructureRareData::cachedPropertyNameEnumerator() const
{
    return m_cachedPropertyNameEnumerator.get();
}

inline void StructureRareData::setCachedPropertyNameEnumerator(VM& vm, JSPropertyNameEnumerator* enumerator)
{
    m_cachedPropertyNameEnumerator.set(vm, this, enumerator);
}

inline JSImmutableButterfly* StructureRareData::cachedPropertyNames(CachedPropertyNamesKind kind) const
{
    ASSERT(!isCompilationThread());
    auto* butterfly = m_cachedPropertyNames[static_cast<unsigned>(kind)].unvalidatedGet();
    if (butterfly == cachedPropertyNamesSentinel())
        return nullptr;
    return butterfly;
}

inline JSImmutableButterfly* StructureRareData::cachedPropertyNamesIgnoringSentinel(CachedPropertyNamesKind kind) const
{
    ASSERT(!isCompilationThread());
    return m_cachedPropertyNames[static_cast<unsigned>(kind)].unvalidatedGet();
}

inline JSImmutableButterfly* StructureRareData::cachedPropertyNamesConcurrently(CachedPropertyNamesKind kind) const
{
    auto* butterfly = m_cachedPropertyNames[static_cast<unsigned>(kind)].unvalidatedGet();
    if (butterfly == cachedPropertyNamesSentinel())
        return nullptr;
    return butterfly;
}

inline void StructureRareData::setCachedPropertyNames(VM& vm, CachedPropertyNamesKind kind, JSImmutableButterfly* butterfly)
{
    if (butterfly == cachedPropertyNamesSentinel()) {
        m_cachedPropertyNames[static_cast<unsigned>(kind)].setWithoutWriteBarrier(butterfly);
        return;
    }

    WTF::storeStoreFence();
    m_cachedPropertyNames[static_cast<unsigned>(kind)].set(vm, this, butterfly);
}

inline bool StructureRareData::canCacheSpecialProperty(CachedSpecialPropertyKey key)
{
    ASSERT(!isCompilationThread() && !Thread::mayBeGCThread());
    auto* cache = m_specialPropertyCache.get();
    if (!cache)
        return true;
    return cache->m_cache[static_cast<unsigned>(key)].m_value.get() != JSCell::seenMultipleCalleeObjects();
}

inline SpecialPropertyCache& StructureRareData::ensureSpecialPropertyCache()
{
    ASSERT(!isCompilationThread() && !Thread::mayBeGCThread());
    if (auto* cache = m_specialPropertyCache.get())
        return *cache;
    return ensureSpecialPropertyCacheSlow();
}

inline void StructureRareData::cacheSpecialProperty(JSGlobalObject* globalObject, VM& vm, Structure* ownStructure, JSValue value, CachedSpecialPropertyKey key, const PropertySlot& slot)
{
    if (!canCacheSpecialProperty(key))
        return;
    return cacheSpecialPropertySlow(globalObject, vm, ownStructure, value, key, slot);
}

} // namespace JSC
