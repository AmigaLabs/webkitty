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

WI.CSSQueryController = class CSSQueryController extends WI.QueryController
{
    constructor(values)
    {
        console.assert(Array.isArray(values), values);

        super();

        this._values = values || [];
        this._cachedSpecialCharacterIndicesForValueMap = new Map;
    }

    // Public

    addValues(values)
    {
        console.assert(Array.isArray(values), values);
        if (!values.length)
            return;

        this._values.pushAll(values);
    }

    reset()
    {
        this._values = [];
        this._cachedSpecialCharacterIndicesForValueMap.clear();
    }

    executeQuery(query)
    {
        if (!query || !this._values.length)
            return [];

        query = query.toLowerCase();

        let results = [];

        for (let value of this._values) {
            if (!this._cachedSpecialCharacterIndicesForValueMap.has(value))
                this._cachedSpecialCharacterIndicesForValueMap.set(value, this._findSpecialCharacterIndices(value));

            let matches = this.findQueryMatches(query, value.toLowerCase(), this._cachedSpecialCharacterIndicesForValueMap.get(value));
            if (matches.length)
                results.push(new WI.QueryResult(value, matches));
        }

        return results.sort((a, b) => {
            if (a.rank === b.rank)
                return a.value.extendedLocaleCompare(b.value);
            return b.rank - a.rank;
        });
    }

    // Private

    _findSpecialCharacterIndices(string)
    {
        if (!string.length)
            return [];

        const separators = "-_";

        // Special characters include the following:
        // 1. The first character.
        // 2. Uppercase characters that follow a lowercase letter.
        // 3. Separators and the first character following the separator.
        let indices = [0];

        for (let i = 1; i < string.length; ++i) {
            let character = string[i];
            let isSpecial = false;

            if (separators.includes(character))
                isSpecial = true;
            else {
                let previousCharacter = string[i - 1];
                if (separators.includes(previousCharacter))
                    isSpecial = true;
                else if (character.isUpperCase() && previousCharacter.isLowerCase())
                    isSpecial = true;
            }

            if (isSpecial)
                indices.push(i);
        }

        return indices;
    }
};
