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

#include "config.h"
#include "WindowOrWorkerGlobalScope.h"

#include "ExceptionOr.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "MessagePort.h"
#include "SerializedScriptValue.h"
#include "StructuredSerializeOptions.h"

namespace WebCore {

void WindowOrWorkerGlobalScope::reportError(JSDOMGlobalObject& globalObject, JSC::JSValue error)
{
    auto& vm = globalObject.vm();
    RELEASE_ASSERT(vm.currentThreadIsHoldingAPILock());
    auto* exception = JSC::jsDynamicCast<JSC::Exception*>(vm, error);
    if (!exception)
        exception = JSC::Exception::create(vm, error);

    reportException(&globalObject, exception);
}

ExceptionOr<JSC::JSValue> WindowOrWorkerGlobalScope::structuredClone(JSDOMGlobalObject& globalObject, JSC::JSValue value, StructuredSerializeOptions&& options)
{
    Vector<RefPtr<MessagePort>> ports;
    auto messageData = SerializedScriptValue::create(globalObject, value, WTFMove(options.transfer), ports, SerializationContext::WindowPostMessage);
    if (messageData.hasException())
        return messageData.releaseException();

    auto disentangledPorts = MessagePort::disentanglePorts(WTFMove(ports));
    if (disentangledPorts.hasException())
        return disentangledPorts.releaseException();

    Vector<RefPtr<MessagePort>> entangledPorts;
    if (auto* scriptExecutionContext = globalObject.scriptExecutionContext())
        entangledPorts = MessagePort::entanglePorts(*scriptExecutionContext, disentangledPorts.releaseReturnValue());

    return messageData.returnValue()->deserialize(globalObject, &globalObject, WTFMove(entangledPorts));
}

} // namespace WebCore
