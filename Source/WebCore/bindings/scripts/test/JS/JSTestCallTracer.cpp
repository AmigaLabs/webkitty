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
#include "JSTestCallTracer.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "IDLTypes.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertBase.h"
#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNullable.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMConvertUnion.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSNode.h"
#include "ScriptExecutionContext.h"
#include "TestAttributeCallTracer.h"
#include "TestInterfaceCallTracer.h"
#include "TestOperationCallTracer.h"
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
#include <wtf/Variant.h>


namespace WebCore {
using namespace JSC;

// Functions

static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationInterface);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationSpecified);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithArguments);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithNullableArgument);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithVariantArgument);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithNullableVariantArgument);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithOptionalVariantArgument);
static JSC_DECLARE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithDefaultVariantArgument);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestCallTracerConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsTestCallTracer_testAttributeInterface);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestCallTracer_testAttributeInterface);
static JSC_DECLARE_CUSTOM_GETTER(jsTestCallTracer_testAttributeSpecified);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestCallTracer_testAttributeSpecified);
static JSC_DECLARE_CUSTOM_GETTER(jsTestCallTracer_testAttributeWithVariant);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestCallTracer_testAttributeWithVariant);
static JSC_DECLARE_CUSTOM_GETTER(jsTestCallTracer_testReadonlyAttribute);

class JSTestCallTracerPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestCallTracerPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestCallTracerPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestCallTracerPrototype>(vm.heap)) JSTestCallTracerPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestCallTracerPrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestCallTracerPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestCallTracerPrototype, JSTestCallTracerPrototype::Base);

using JSTestCallTracerDOMConstructor = JSDOMConstructorNotConstructable<JSTestCallTracer>;

/* Hash table for constructor */

static const HashTableValue JSTestCallTracerConstructorTableValues[] =
{
    { "testConstValue", JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { (long long)(false) } },
};

static_assert(TestCallTracer::testConstValue == false, "testConstValue in TestCallTracer does not match value from IDL");

template<> const ClassInfo JSTestCallTracerDOMConstructor::s_info = { "TestCallTracer", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestCallTracerDOMConstructor) };

template<> JSValue JSTestCallTracerDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestCallTracerDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestCallTracer::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestCallTracer"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    reifyStaticProperties(vm, JSTestCallTracer::info(), JSTestCallTracerConstructorTableValues, *this);
}

/* Hash table for prototype */

static const HashTableValue JSTestCallTracerPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCallTracerConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "testAttributeInterface", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCallTracer_testAttributeInterface), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCallTracer_testAttributeInterface) } },
    { "testAttributeSpecified", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCallTracer_testAttributeSpecified), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCallTracer_testAttributeSpecified) } },
    { "testAttributeWithVariant", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCallTracer_testAttributeWithVariant), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCallTracer_testAttributeWithVariant) } },
    { "testReadonlyAttribute", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCallTracer_testReadonlyAttribute), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "testOperationInterface", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationInterface), (intptr_t) (0) } },
    { "testOperationSpecified", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationSpecified), (intptr_t) (0) } },
    { "testOperationWithArguments", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationWithArguments), (intptr_t) (3) } },
    { "testOperationWithNullableArgument", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationWithNullableArgument), (intptr_t) (1) } },
    { "testOperationWithVariantArgument", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationWithVariantArgument), (intptr_t) (1) } },
    { "testOperationWithNullableVariantArgument", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationWithNullableVariantArgument), (intptr_t) (1) } },
    { "testOperationWithOptionalVariantArgument", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationWithOptionalVariantArgument), (intptr_t) (0) } },
    { "testOperationWithDefaultVariantArgument", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCallTracerPrototypeFunction_testOperationWithDefaultVariantArgument), (intptr_t) (0) } },
    { "testConstValue", JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::ConstantInteger, NoIntrinsic, { (long long)(false) } },
};

const ClassInfo JSTestCallTracerPrototype::s_info = { "TestCallTracer", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestCallTracerPrototype) };

void JSTestCallTracerPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestCallTracer::info(), JSTestCallTracerPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestCallTracer::s_info = { "TestCallTracer", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestCallTracer) };

JSTestCallTracer::JSTestCallTracer(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestCallTracer>&& impl)
    : JSDOMWrapper<TestCallTracer>(structure, globalObject, WTFMove(impl))
{
}

void JSTestCallTracer::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestCallTracer>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestCallTracer::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestCallTracerPrototype::create(vm, &globalObject, JSTestCallTracerPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestCallTracer::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestCallTracer>(vm, globalObject);
}

JSValue JSTestCallTracer::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestCallTracerDOMConstructor, DOMConstructorID::TestCallTracer>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestCallTracer::destroy(JSC::JSCell* cell)
{
    JSTestCallTracer* thisObject = static_cast<JSTestCallTracer*>(cell);
    thisObject->JSTestCallTracer::~JSTestCallTracer();
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCallTracerConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestCallTracerPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestCallTracer::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsTestCallTracer_testAttributeInterfaceGetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testAttributeInterface"_s);
    RELEASE_AND_RETURN(throwScope, (toJS<IDLBoolean>(lexicalGlobalObject, throwScope, impl.testAttributeInterface())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCallTracer_testAttributeInterface, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::get<jsTestCallTracer_testAttributeInterfaceGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSTestCallTracer_testAttributeInterfaceSetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLBoolean>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testAttributeInterface"_s, { TestInterfaceCallTracer::processArgument(impl, nativeValue) });
    invokeFunctorPropagatingExceptionIfNecessary(lexicalGlobalObject, throwScope, [&] {
        return impl.setTestAttributeInterface(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestCallTracer_testAttributeInterface, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::set<setJSTestCallTracer_testAttributeInterfaceSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsTestCallTracer_testAttributeSpecifiedGetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    if (UNLIKELY(impl.hasActiveTestAttributeCallTracer()))
        TestAttributeCallTracer::recordAction(impl, "testAttributeSpecified"_s);
    RELEASE_AND_RETURN(throwScope, (toJS<IDLBoolean>(lexicalGlobalObject, throwScope, impl.testAttributeSpecified())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCallTracer_testAttributeSpecified, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::get<jsTestCallTracer_testAttributeSpecifiedGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSTestCallTracer_testAttributeSpecifiedSetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLBoolean>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    if (UNLIKELY(impl.hasActiveTestAttributeCallTracer()))
        TestAttributeCallTracer::recordAction(impl, "testAttributeSpecified"_s, { TestAttributeCallTracer::processArgument(impl, nativeValue) });
    invokeFunctorPropagatingExceptionIfNecessary(lexicalGlobalObject, throwScope, [&] {
        return impl.setTestAttributeSpecified(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestCallTracer_testAttributeSpecified, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::set<setJSTestCallTracer_testAttributeSpecifiedSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsTestCallTracer_testAttributeWithVariantGetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testAttributeWithVariant"_s);
    RELEASE_AND_RETURN(throwScope, (toJS<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>(lexicalGlobalObject, *thisObject.globalObject(), throwScope, impl.testAttributeWithVariant())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCallTracer_testAttributeWithVariant, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::get<jsTestCallTracer_testAttributeWithVariantGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSTestCallTracer_testAttributeWithVariantSetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testAttributeWithVariant"_s, { TestInterfaceCallTracer::processArgument(impl, nativeValue) });
    invokeFunctorPropagatingExceptionIfNecessary(lexicalGlobalObject, throwScope, [&] {
        return impl.setTestAttributeWithVariant(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestCallTracer_testAttributeWithVariant, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::set<setJSTestCallTracer_testAttributeWithVariantSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsTestCallTracer_testReadonlyAttributeGetter(JSGlobalObject& lexicalGlobalObject, JSTestCallTracer& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLBoolean>(lexicalGlobalObject, throwScope, impl.testReadonlyAttribute())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCallTracer_testReadonlyAttribute, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCallTracer>::get<jsTestCallTracer_testReadonlyAttributeGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationInterfaceBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationInterface"_s);
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationInterface(); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationInterface, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationInterfaceBody>(*lexicalGlobalObject, *callFrame, "testOperationInterface");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationSpecifiedBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(impl.hasActiveTestOperationCallTracer()))
        TestOperationCallTracer::recordAction(impl, "testOperationSpecified"_s);
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationSpecified(); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationSpecified, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationSpecifiedBody>(*lexicalGlobalObject, *callFrame, "testOperationSpecified");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationWithArgumentsBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 3))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto a = convert<IDLBoolean>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument1 = callFrame->uncheckedArgument(1);
    auto b = convert<IDLFloat>(*lexicalGlobalObject, argument1.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    EnsureStillAliveScope argument2 = callFrame->uncheckedArgument(2);
    auto c = convert<IDLDOMString>(*lexicalGlobalObject, argument2.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationWithArguments"_s, { TestInterfaceCallTracer::processArgument(impl, a), TestInterfaceCallTracer::processArgument(impl, b), TestInterfaceCallTracer::processArgument(impl, c) });
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationWithArguments(WTFMove(a), WTFMove(b), WTFMove(c)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithArguments, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationWithArgumentsBody>(*lexicalGlobalObject, *callFrame, "testOperationWithArguments");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationWithNullableArgumentBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto nodeNullableArg = convert<IDLNullable<IDLInterface<Node>>>(*lexicalGlobalObject, argument0.value(), [](JSC::JSGlobalObject& lexicalGlobalObject, JSC::ThrowScope& scope) { throwArgumentTypeError(lexicalGlobalObject, scope, 0, "nodeNullableArg", "TestCallTracer", "testOperationWithNullableArgument", "Node"); });
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationWithNullableArgument"_s, { TestInterfaceCallTracer::processArgument(impl, nodeNullableArg) });
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationWithNullableArgument(WTFMove(nodeNullableArg)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithNullableArgument, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationWithNullableArgumentBody>(*lexicalGlobalObject, *callFrame, "testOperationWithNullableArgument");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationWithVariantArgumentBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto variantArg = convert<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationWithVariantArgument"_s, { TestInterfaceCallTracer::processArgument(impl, variantArg) });
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationWithVariantArgument(WTFMove(variantArg)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithVariantArgument, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationWithVariantArgumentBody>(*lexicalGlobalObject, *callFrame, "testOperationWithVariantArgument");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationWithNullableVariantArgumentBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(callFrame->argumentCount() < 1))
        return throwVMError(lexicalGlobalObject, throwScope, createNotEnoughArgumentsError(lexicalGlobalObject));
    EnsureStillAliveScope argument0 = callFrame->uncheckedArgument(0);
    auto variantNullableArg = convert<IDLNullable<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationWithNullableVariantArgument"_s, { TestInterfaceCallTracer::processArgument(impl, variantNullableArg) });
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationWithNullableVariantArgument(WTFMove(variantNullableArg)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithNullableVariantArgument, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationWithNullableVariantArgumentBody>(*lexicalGlobalObject, *callFrame, "testOperationWithNullableVariantArgument");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationWithOptionalVariantArgumentBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->argument(0);
    auto variantOptionalArg = argument0.value().isUndefined() ? std::optional<Converter<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>::ReturnType>() : std::optional<Converter<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>::ReturnType>(convert<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>(*lexicalGlobalObject, argument0.value()));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationWithOptionalVariantArgument"_s, { TestInterfaceCallTracer::processArgument(impl, variantOptionalArg) });
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationWithOptionalVariantArgument(WTFMove(variantOptionalArg)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithOptionalVariantArgument, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationWithOptionalVariantArgumentBody>(*lexicalGlobalObject, *callFrame, "testOperationWithOptionalVariantArgument");
}

static inline JSC::EncodedJSValue jsTestCallTracerPrototypeFunction_testOperationWithDefaultVariantArgumentBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCallTracer>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    EnsureStillAliveScope argument0 = callFrame->argument(0);
    auto variantDefaultArg = argument0.value().isUndefined() ? emptyString() : convert<IDLUnion<IDLBoolean, IDLFloat, IDLDOMString>>(*lexicalGlobalObject, argument0.value());
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    if (UNLIKELY(impl.hasActiveTestInterfaceCallTracer()))
        TestInterfaceCallTracer::recordAction(impl, "testOperationWithDefaultVariantArgument"_s, { TestInterfaceCallTracer::processArgument(impl, variantDefaultArg) });
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLUndefined>(*lexicalGlobalObject, throwScope, [&]() -> decltype(auto) { return impl.testOperationWithDefaultVariantArgument(WTFMove(variantDefaultArg)); })));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCallTracerPrototypeFunction_testOperationWithDefaultVariantArgument, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCallTracer>::call<jsTestCallTracerPrototypeFunction_testOperationWithDefaultVariantArgumentBody>(*lexicalGlobalObject, *callFrame, "testOperationWithDefaultVariantArgument");
}

JSC::IsoSubspace* JSTestCallTracer::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestCallTracer.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestCallTracer> || !JSTestCallTracer::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestCallTracer>)
        spaces.m_subspaceForTestCallTracer = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestCallTracer);
    else
        spaces.m_subspaceForTestCallTracer = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestCallTracer);
    auto* space = spaces.m_subspaceForTestCallTracer.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    void (*myVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSTestCallTracer::visitOutputConstraints;
    void (*jsCellVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSC::JSCell::visitOutputConstraints;
    if (myVisitOutputConstraint != jsCellVisitOutputConstraint)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestCallTracer::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestCallTracer*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestCallTracerOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestCallTracerOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestCallTracer = static_cast<JSTestCallTracer*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestCallTracer->wrapped(), jsTestCallTracer);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestCallTracer@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore14TestCallTracerE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestCallTracer>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
    void* expectedVTablePointer = __identifier("??_7TestCallTracer@WebCore@@6B@");
#else
    void* expectedVTablePointer = &_ZTVN7WebCore14TestCallTracerE[2];
#endif

    // If this fails TestCallTracer does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestCallTracer>::value, "TestCallTracer is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestCallTracer has subclasses. If TestCallTracer has subclasses that get passed
    // to toJS() we currently require TestCallTracer you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestCallTracer>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestCallTracer& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestCallTracer* JSTestCallTracer::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestCallTracer*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
