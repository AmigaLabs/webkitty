/*
 * Copyright (C) 2022 Apple Inc. All rights reserved.
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

#include "PushServiceConnection.h"

namespace WebPushD {

class MockPushServiceConnection final : public PushServiceConnection {
public:
    MockPushServiceConnection();
    ~MockPushServiceConnection();

    WebCore::PushCrypto::ClientKeys generateClientKeys() final;

    void subscribe(const String& topic, const Vector<uint8_t>& vapidPublicKey, SubscribeHandler&&) override;
    void unsubscribe(const String& topic, const Vector<uint8_t>& vapidPublicKey, UnsubscribeHandler&&) override;

    Vector<String> enabledTopics() override;
    Vector<String> ignoredTopics() override;
    Vector<String> opportunisticTopics() override;
    Vector<String> nonWakingTopics() override;

    void setEnabledTopics(Vector<String>&&) override;
    void setIgnoredTopics(Vector<String>&&) override;
    void setOpportunisticTopics(Vector<String>&&) override;
    void setNonWakingTopics(Vector<String>&&) override;

    void setTopicLists(TopicLists&&) override;
};

} // namespace WebPushD
