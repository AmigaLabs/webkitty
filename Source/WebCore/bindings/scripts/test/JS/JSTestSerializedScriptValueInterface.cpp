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

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "JSTestSerializedScriptValueInterface.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertSequences.h"
#include "JSDOMConvertSerializedScriptValue.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSMessagePort.h"
#include "ScriptExecutionContext.h"
#include "SerializedScriptValue.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/FunctionPrototype.h>
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/JSArray.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>


namespace WebCore {
using namespace JSC;

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsTestSerializedScriptValueInterfacePrototypeFunctionFunction(JSC::JSGlobalObject*, JSC::CallFrame*);
JSC::EncodedJSValue JSC_HOST_CALL jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionReturning(JSC::JSGlobalObject*, JSC::CallFrame*);

// Attributes

JSC::EncodedJSValue jsTestSerializedScriptValueInterfaceConstructor(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestSerializedScriptValueInterfaceConstructor(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestSerializedScriptValueInterfaceValue(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestSerializedScriptValueInterfaceValue(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestSerializedScriptValueInterfaceReadonlyValue(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsTestSerializedScriptValueInterfaceCachedValue(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestSerializedScriptValueInterfaceCachedValue(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestSerializedScriptValueInterfacePorts(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsTestSerializedScriptValueInterfaceCachedReadonlyValue(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);

class JSTestSerializedScriptValueInterfacePrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestSerializedScriptValueInterfacePrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestSerializedScriptValueInterfacePrototype* ptr = new (NotNull, JSC::allocateCell<JSTestSerializedScriptValueInterfacePrototype>(vm.heap)) JSTestSerializedScriptValueInterfacePrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestSerializedScriptValueInterfacePrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestSerializedScriptValueInterfacePrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestSerializedScriptValueInterfacePrototype, JSTestSerializedScriptValueInterfacePrototype::Base);

using JSTestSerializedScriptValueInterfaceConstructor = JSDOMConstructorNotConstructable<JSTestSerializedScriptValueInterface>;

template<> JSValue JSTestSerializedScriptValueInterfaceConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestSerializedScriptValueInterfaceConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestSerializedScriptValueInterface::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestSerializedScriptValueInterface"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestSerializedScriptValueInterfaceConstructor::s_info = { "TestSerializedScriptValueInterface", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterfaceConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestSerializedScriptValueInterfacePrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializedScriptValueInterfaceConstructor) } },
    { "value", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializedScriptValueInterfaceValue) } },
    { "readonlyValue", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceReadonlyValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "cachedValue", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceCachedValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestSerializedScriptValueInterfaceCachedValue) } },
    { "ports", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfacePorts), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "cachedReadonlyValue", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestSerializedScriptValueInterfaceCachedReadonlyValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "function", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestSerializedScriptValueInterfacePrototypeFunctionFunction), (intptr_t) (1) } },
    { "functionReturning", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionReturning), (intptr_t) (0) } },
};

const ClassInfo JSTestSerializedScriptValueInterfacePrototype::s_info = { "TestSerializedScriptValueInterface", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterfacePrototype) };

void JSTestSerializedScriptValueInterfacePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestSerializedScriptValueInterface::info(), JSTestSerializedScriptValueInterfacePrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestSerializedScriptValueInterface::s_info = { "TestSerializedScriptValueInterface", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestSerializedScriptValueInterface) };

JSTestSerializedScriptValueInterface::JSTestSerializedScriptValueInterface(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestSerializedScriptValueInterface>&& impl)
    : JSDOMWrapper<TestSerializedScriptValueInterface>(structure, globalObject, WTFMove(impl))
{
}

void JSTestSerializedScriptValueInterface::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestSerializedScriptValueInterface>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestSerializedScriptValueInterface::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestSerializedScriptValueInterfacePrototype::create(vm, &globalObject, JSTestSerializedScriptValueInterfacePrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestSerializedScriptValueInterface::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestSerializedScriptValueInterface>(vm, globalObject);
}

JSValue JSTestSerializedScriptValueInterface::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestSerializedScriptValueInterfaceConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestSerializedScriptValueInterface::destroy(JSC::JSCell* cell)
{
    JSTestSerializedScriptValueInterface* thisObject = static_cast<JSTestSerializedScriptValueInterface*>(cell);
    thisObject->JSTestSerializedScriptValueInterface::~JSTestSerializedScriptValueInterface();
}

template<> inline JSTestSerializedScriptValueInterface* IDLAttribute<JSTestSerializedScriptValueInterface>::cast(JSGlobalObject& lexicalGlobalObject, EncodedJSValue thisValue)
{
    return jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSC::getVM(&lexicalGlobalObject), JSValue::decode(thisValue));
}

template<> inline JSTestSerializedScriptValueInterface* IDLOperation<JSTestSerializedScriptValueInterface>::cast(JSGlobalObject& lexicalGlobalObject, CallFrame& callFrame)
{
    return jsDynamicCast<JSTestSerializedScriptValueInterface*>(JSC::getVM(&lexicalGlobalObject), callFrame.thisValue());
}

EncodedJSValue jsTestSerializedScriptValueInterfaceConstructor(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestSerializedScriptValueInterface::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

bool setJSTestSerializedScriptValueInterfaceConstructor(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestSerializedScriptValueInterfacePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype)) {
        throwVMTypeError(lexicalGlobalObject, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return prototype->putDirect(vm, vm.propertyNames->constructor, JSValue::decode(encodedValue));
}

static inline JSValue jsTestSerializedScriptValueInterfaceValueGetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLSerializedScriptValue<SerializedScriptValue>>(lexicalGlobalObject, *thisObject.globalObject(), throwScope, impl.value())));
}

EncodedJSValue jsTestSerializedScriptValueInterfaceValue(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::get<jsTestSerializedScriptValueInterfaceValueGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "value");
}

static inline bool setJSTestSerializedScriptValueInterfaceValueSetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLSerializedScriptValue<SerializedScriptValue>>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    AttributeSetter::call(lexicalGlobalObject, throwScope, [&] {
        return impl.setValue(WTFMove(nativeValue));
    });
    return true;
}

bool setJSTestSerializedScriptValueInterfaceValue(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::set<setJSTestSerializedScriptValueInterfaceValueSetter>(*lexicalGlobalObject, thisValue, encodedValue, "value");
}

static inline JSValue jsTestSerializedScriptValueInterfaceReadonlyValueGetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLSerializedScriptValue<SerializedScriptValue>>(lexicalGlobalObject, *thisObject.globalObject(), throwScope, impl.readonlyValue())));
}

EncodedJSValue jsTestSerializedScriptValueInterfaceReadonlyValue(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::get<jsTestSerializedScriptValueInterfaceReadonlyValueGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "readonlyValue");
}

static inline JSValue jsTestSerializedScriptValueInterfaceCachedValueGetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    if (JSValue cachedValue = thisObject.m_cachedValue.get())
        return cachedValue;
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLSerializedScriptValue<SerializedScriptValue>>(lexicalGlobalObject, *thisObject.globalObject(), throwScope, impl.cachedValue());
    RETURN_IF_EXCEPTION(throwScope, { });
    thisObject.m_cachedValue.set(JSC::getVM(&lexicalGlobalObject), &thisObject, result);
    return result;
}

EncodedJSValue jsTestSerializedScriptValueInterfaceCachedValue(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::get<jsTestSerializedScriptValueInterfaceCachedValueGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "cachedValue");
}

static inline bool setJSTestSerializedScriptValueInterfaceCachedValueSetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLSerializedScriptValue<SerializedScriptValue>>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    AttributeSetter::call(lexicalGlobalObject, throwScope, [&] {
        return impl.setCachedValue(WTFMove(nativeValue));
    });
    return true;
}

bool setJSTestSerializedScriptValueInterfaceCachedValue(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::set<setJSTestSerializedScriptValueInterfaceCachedValueSetter>(*lexicalGlobalObject, thisValue, encodedValue, "cachedValue");
}

static inline JSValue jsTestSerializedScriptValueInterfacePortsGetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLSequence<IDLInterface<MessagePort>>>(lexicalGlobalObject, *thisObject.globalObject(), throwScope, impl.ports())));
}

EncodedJSValue jsTestSerializedScriptValueInterfacePorts(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::get<jsTestSerializedScriptValueInterfacePortsGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "ports");
}

static inline JSValue jsTestSerializedScriptValueInterfaceCachedReadonlyValueGetter(JSGlobalObject& lexicalGlobalObject, JSTestSerializedScriptValueInterface& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    if (JSValue cachedValue = thisObject.m_cachedReadonlyValue.get())
        return cachedValue;
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLSerializedScriptValue<SerializedScriptValue>>(lexicalGlobalObject, *thisObject.globalObject(), throwScope, impl.cachedReadonlyValue());
    RETURN_IF_EXCEPTION(throwScope, { });
    thisObject.m_cachedReadonlyValue.set(JSC::getVM(&lexicalGlobalObject), &thisObject, result);
    return result;
}

EncodedJSValue jsTestSerializedScriptValueInterfaceCachedReadonlyValue(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestSerializedScriptValueInterface>::get<jsTestSerializedScriptValueInterfaceCachedReadonlyValueGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "cachedReadonlyValue");
}

static inline JSC::EncodedJSValue jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestSerializedScriptValueInterface>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto value = convert<IDLSerializedScriptValue<SerializedScriptValue>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    throwScope.release();
    impl.function(WTFMove(value));
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsTestSerializedScriptValueInterfacePrototypeFunctionFunction(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    return IDLOperation<JSTestSerializedScriptValueInterface>::call<jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionBody>(*lexicalGlobalObject, *callFrame, "function");
}

static inline JSC::EncodedJSValue jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionReturningBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestSerializedScriptValueInterface>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLSerializedScriptValue<SerializedScriptValue>>(*lexicalGlobalObject, *castedThis->globalObject(), impl.functionReturning())));
}

EncodedJSValue JSC_HOST_CALL jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionReturning(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame)
{
    return IDLOperation<JSTestSerializedScriptValueInterface>::call<jsTestSerializedScriptValueInterfacePrototypeFunctionFunctionReturningBody>(*lexicalGlobalObject, *callFrame, "functionReturning");
}

JSC::IsoSubspace* JSTestSerializedScriptValueInterface::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestSerializedScriptValueInterface.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestSerializedScriptValueInterface> || !JSTestSerializedScriptValueInterface::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestSerializedScriptValueInterface>)
        spaces.m_subspaceForTestSerializedScriptValueInterface = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestSerializedScriptValueInterface);
    else
        spaces.m_subspaceForTestSerializedScriptValueInterface = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestSerializedScriptValueInterface);
    auto* space = spaces.m_subspaceForTestSerializedScriptValueInterface.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    if (&JSTestSerializedScriptValueInterface::visitOutputConstraints != &JSC::JSCell::visitOutputConstraints)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestSerializedScriptValueInterface::visitChildren(JSCell* cell, SlotVisitor& visitor)
{
    auto* thisObject = jsCast<JSTestSerializedScriptValueInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitChildren(thisObject, visitor);
    visitor.append(thisObject->m_cachedValue);
    visitor.append(thisObject->m_cachedReadonlyValue);
}

void JSTestSerializedScriptValueInterface::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestSerializedScriptValueInterface*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestSerializedScriptValueInterfaceOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestSerializedScriptValueInterfaceOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestSerializedScriptValueInterface = static_cast<JSTestSerializedScriptValueInterface*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestSerializedScriptValueInterface->wrapped(), jsTestSerializedScriptValueInterface);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestSerializedScriptValueInterface@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore34TestSerializedScriptValueInterfaceE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestSerializedScriptValueInterface>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
    void* expectedVTablePointer = __identifier("??_7TestSerializedScriptValueInterface@WebCore@@6B@");
#else
    void* expectedVTablePointer = &_ZTVN7WebCore34TestSerializedScriptValueInterfaceE[2];
#endif

    // If this fails TestSerializedScriptValueInterface does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestSerializedScriptValueInterface>::value, "TestSerializedScriptValueInterface is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestSerializedScriptValueInterface has subclasses. If TestSerializedScriptValueInterface has subclasses that get passed
    // to toJS() we currently require TestSerializedScriptValueInterface you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestSerializedScriptValueInterface>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestSerializedScriptValueInterface& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestSerializedScriptValueInterface* JSTestSerializedScriptValueInterface::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestSerializedScriptValueInterface*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}

#endif // ENABLE(Condition1) || ENABLE(Condition2)
