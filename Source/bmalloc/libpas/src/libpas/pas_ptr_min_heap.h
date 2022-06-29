/*
 * Copyright (c) 2021 Apple Inc. All rights reserved.
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

#ifndef PAS_PTR_MIN_HEAP_H
#define PAS_PTR_MIN_HEAP_H

#include "pas_min_heap.h"

PAS_BEGIN_EXTERN_C;

static inline int pas_ptr_min_heap_compare(void** left_ptr, void** right_ptr)
{
    void* left;
    void* right;

    left = *left_ptr;
    right = *right_ptr;

    if (left < right)
        return -1;
    if (left == right)
        return 0;
    return 1;
}

static inline size_t pas_ptr_min_heap_get_index(void** element_ptr)
{
    PAS_UNUSED_PARAM(element_ptr);
    PAS_ASSERT(!"Should not be reached");
    return 0;
}

static inline void pas_ptr_min_heap_set_index(void** element_ptr, size_t index)
{
    PAS_UNUSED_PARAM(element_ptr);
    PAS_UNUSED_PARAM(index);
}

PAS_CREATE_MIN_HEAP(pas_ptr_min_heap,
                    void*,
                    10,
                    .compare = pas_ptr_min_heap_compare,
                    .get_index = pas_ptr_min_heap_get_index,
                    .set_index = pas_ptr_min_heap_set_index);

PAS_END_EXTERN_C;

#endif /* PAS_PTR_MIN_HEAP_H */

