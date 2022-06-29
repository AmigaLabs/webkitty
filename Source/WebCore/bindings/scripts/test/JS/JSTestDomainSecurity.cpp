/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSTestDomainSecurity.h"

#include "ActiveDOMObject.h"
#include "CustomElementReactionQueue.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "IDLTypes.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMBindingSecurity.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSNode.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/FunctionPrototype.h>
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>


namespace WebCore {
using namespace JSC;

// Functions

static JSC_DECLARE_HOST_FUNCTION(jsTestDomainSecurityPrototypeFunction_excitingFunction);
static JSC_DECLARE_HOST_FUNCTION(jsTestDomainSecurityPrototypeFunction_postMessage);
static JSC_DECLARE_HOST_FUNCTION(jsTestDomainSecurityPrototypeFunction_overloadedMethod);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestDomainSecurityConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsTestDomainSecurity_excitingAttr);

class JSTestDomainSecurityPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestDomainSecurityPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestDomainSecurityPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestDomainSecurityPrototype>(vm)) JSTestDomainSecurityPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestDomainSecurityPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestDomainSecurityPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestDomainSecurityPrototype, JSTestDomainSecurityPrototype::Base);

using JSTestDomainSecurityDOMConstructor = JSDOMConstructorNotConstructable<JSTestDomainSecurity>;

/* Hash table */

static const struct CompactHashIndex JSTestDomainSecurityTableIndex[2] = {
    { 0, -1 },
    { -1, -1 },
};


static const HashTableValue JSTestDomainSecurityTableValues[] =
{
    { "excitingAttr", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestDomainSecurity_excitingAttr), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

static const HashTable JSTestDomainSecurityTable = { 1, 1, true, JSTestDomainSecurity::info(), JSTestDomainSecurityTableValues, JSTestDomainSecurityTableIndex };
template<> const ClassInfo JSTestDomainSecurityDOMConstructor::s_info = { "TestDomainSecurity", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDomainSecurityDOMConstructor) };

template<> JSValue JSTestDomainSecurityDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestDomainSecurityDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "TestDomainSecurity"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSTestDomainSecurity::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSTestDomainSecurityPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestDomainSecurityConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "excitingFunction", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestDomainSecurityPrototypeFunction_excitingFunction), (intptr_t) (1) } },
    { "postMessage", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestDomainSecurityPrototypeFunction_postMessage), (intptr_t) (1) } },
    { "overloadedMethod", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestDomainSecurityPrototypeFunction_overloadedMethod), (intptr_t) (1) } },
};

const ClassInfo JSTestDomainSecurityPrototype::s_info = { "TestDomainSecurity", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDomainSecurityPrototype) };

void JSTestDomainSecurityPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestDomainSecurity::info(), JSTestDomainSecurityPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestDomainSecurity::s_info = { "TestDomainSecurity", &Base::s_info, &JSTestDomainSecurityTable, nullptr, CREATE_METHOD_TABLE(JSTestDomainSecurity) };

JSTestDomainSecurity::JSTestDomainSecurity(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestDomainSecurity>&& impl)
    : JSDOMWrapper<TestDomainSecurity>(structure, globalObject, WTFMove(impl))
{
}

void JSTestDomainSecurity::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestDomainSecurity>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestDomainSecurity::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestDomainSecurityPrototype::create(vm, &globalObject, JSTestDomainSecurityPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestDomainSecurity::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestDomainSecurity>(vm, globalObject);
}

JSValue JSTestDomainSecurity::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestDomainSecurityDOMConstructor, DOMConstructorID::TestDomainSecurity>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestDomainSecurity::destroy(JSC::JSCell* cell)
{
    JSTestDomainSecurity* thisObject = static_cast<JSTestDomainSecurity*>(cell);
    thisObject->JSTestDomainSecurity::~JSTestDomainSecurity();
}

JSC_DEFINE_CUSTOM_GETTER(jsTestDomainSecurityConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestDomainSecurityPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestDomainSecurity::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsTestDomainSecurity_excitingAttrGetter(JSGlobalObject& lexicalGlobalObject, JSTestDomainSecurity& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    bool shouldAllowAccess = BindingSecurity::shouldAllowAccessToDOMWindow(&lexicalGlobalObject, thisObject.wrapped().window(), ThrowSecurityError);
    EXCEPTION_ASSERT_UNUSED(throwScope, !throwScope.exception() || !shouldAllowAccess);
    if (!shouldAllowAccess)
        return jsUndefined();
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLLong>(lexicalGlobalObject, throwScope, impl.excitingAttr())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestDomainSecurity_excitingAttr, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestDomainSecurity>::get<jsTestDomainSecurity_excitingAttrGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSC::EncodedJSValue jsTestDomainSecurityPrototypeFunction_excitingFunctionBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestDomainSecurity>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    bool shouldAllowAccess = BindingSecurity::shouldAllowAccessToDOMWindow(lexicalGlobalObject, castedThis->wrapped().window(), ThrowSecurityError);
    EXCEPTION_ASSERT_UNUSED(throwScope, !throwScope.exception() || !shouldAllowAccess);
    if (!shouldAllowAccess)
        return JSValue::encode(jsUndefined());
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto nextChild = convert<IDLInterface<Node>>(*lexicalGlobalObject, argument0.value(), [](JSC::JSGlobalObject& lexicalGlobalObject, JSC::ThrowScope& scope) { throwArgumentTypeError(lexicalGlobalObject, scope, 0, "nextChild", "TestDomainSecurity", "excitingFunction", "Node"); });
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.excitingFunction(*nextChild); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestDomainSecurityPrototypeFunction_excitingFunction, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestDomainSecurity>::call<jsTestDomainSecurityPrototypeFunction_excitingFunctionBody>(*lexicalGlobalObject, *callFrame, "excitingFunction");
}

static inline JSC::EncodedJSValue jsTestDomainSecurityPrototypeFunction_postMessageBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestDomainSecurity>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto message = convert<IDLDOMString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.postMessage(WTFMove(message)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestDomainSecurityPrototypeFunction_postMessage, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestDomainSecurity>::call<jsTestDomainSecurityPrototypeFunction_postMessageBody>(*lexicalGlobalObject, *callFrame, "postMessage");
}

static inline JSC::EncodedJSValue jsTestDomainSecurityPrototypeFunction_overloadedMethod1Body(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestDomainSecurity>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    CustomElementReactionStack customElementReactionStack(*lexicalGlobalObject);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto param = convert<IDLDOMString>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.overloadedMethod(WTFMove(param)); })));
}

static inline JSC::EncodedJSValue jsTestDomainSecurityPrototypeFunction_overloadedMethod2Body(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestDomainSecurity>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto param1 = convert<IDLInterface<Node>>(*lexicalGlobalObject, argument0.value(), [](JSC::JSGlobalObject& lexicalGlobalObject, JSC::ThrowScope& scope) { throwArgumentTypeError(lexicalGlobalObject, scope, 0, "param1", "TestDomainSecurity", "overloadedMethod", "Node"); });
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto param2 = convert<IDLInterface<Node>>(*lexicalGlobalObject, argument1.value(), [](JSC::JSGlobalObject& lexicalGlobalObject, JSC::ThrowScope& scope) { throwArgumentTypeError(lexicalGlobalObject, scope, 1, "param2", "TestDomainSecurity", "overloadedMethod", "Node"); });
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.overloadedMethod(*param1, *param2); })));
}

static inline JSC::EncodedJSValue jsTestDomainSecurityPrototypeFunction_overloadedMethodOverloadDispatcher(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestDomainSecurity>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    bool shouldAllowAccess = BindingSecurity::shouldAllowAccessToDOMWindow(lexicalGlobalObject, castedThis->wrapped().window(), ThrowSecurityError);
    EXCEPTION_ASSERT_UNUSED(throwScope, !throwScope.exception() || !shouldAllowAccess);
    if (!shouldAllowAccess)
        return JSValue::encode(jsUndefined());
    size_t argsCount = std::min<size_t>(2, callFrame->argumentCount());
    if (argsCount == 1) {
        RELEASE_AND_RETURN(throwScope, (jsTestDomainSecurityPrototypeFunction_overloadedMethod1Body(lexicalGlobalObject, callFrame, castedThis)));
    }
    if (argsCount == 2) {
        RELEASE_AND_RETURN(throwScope, (jsTestDomainSecurityPrototypeFunction_overloadedMethod2Body(lexicalGlobalObject, callFrame, castedThis)));
    }
    return argsCount < 1 ? throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject)) : throwVMTypeError(lexicalGlobalObject, throwScope);
}

JSC_DEFINE_HOST_FUNCTION(jsTestDomainSecurityPrototypeFunction_overloadedMethod, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestDomainSecurity>::call<jsTestDomainSecurityPrototypeFunction_overloadedMethodOverloadDispatcher>(*lexicalGlobalObject, *callFrame, "overloadedMethod");
}

JSC::GCClient::IsoSubspace* JSTestDomainSecurity::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSTestDomainSecurity, UseCustomHeapCellType::No>(vm,
        [] (auto& spaces) { return spaces.m_clientSubspaceForTestDomainSecurity.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForTestDomainSecurity = WTFMove(space); },
        [] (auto& spaces) { return spaces.m_subspaceForTestDomainSecurity.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_subspaceForTestDomainSecurity = WTFMove(space); }
    );
}

void JSTestDomainSecurity::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestDomainSecurity*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestDomainSecurityOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestDomainSecurityOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestDomainSecurity = static_cast<JSTestDomainSecurity*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestDomainSecurity->wrapped(), jsTestDomainSecurity);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestDomainSecurity@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore18TestDomainSecurityE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestDomainSecurity>&& impl)
{

    if constexpr (std::is_polymorphic_v<TestDomainSecurity>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7TestDomainSecurity@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore18TestDomainSecurityE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // TestDomainSecurity has subclasses. If TestDomainSecurity has subclasses that get passed
        // to toJS() we currently require TestDomainSecurity you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<TestDomainSecurity>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestDomainSecurity& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestDomainSecurity* JSTestDomainSecurity::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestDomainSecurity*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
