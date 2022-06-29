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
#include "JSTestCEReactionsStringifier.h"

#include "ActiveDOMObject.h"
#include "CustomElementReactionQueue.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
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

static JSC_DECLARE_HOST_FUNCTION(jsTestCEReactionsStringifierPrototypeFunction_toString);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestCEReactionsStringifierConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsTestCEReactionsStringifier_value);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestCEReactionsStringifier_value);
static JSC_DECLARE_CUSTOM_GETTER(jsTestCEReactionsStringifier_valueWithoutReactions);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestCEReactionsStringifier_valueWithoutReactions);

class JSTestCEReactionsStringifierPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestCEReactionsStringifierPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestCEReactionsStringifierPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestCEReactionsStringifierPrototype>(vm)) JSTestCEReactionsStringifierPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestCEReactionsStringifierPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestCEReactionsStringifierPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestCEReactionsStringifierPrototype, JSTestCEReactionsStringifierPrototype::Base);

using JSTestCEReactionsStringifierDOMConstructor = JSDOMConstructorNotConstructable<JSTestCEReactionsStringifier>;

template<> const ClassInfo JSTestCEReactionsStringifierDOMConstructor::s_info = { "TestCEReactionsStringifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestCEReactionsStringifierDOMConstructor) };

template<> JSValue JSTestCEReactionsStringifierDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestCEReactionsStringifierDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "TestCEReactionsStringifier"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSTestCEReactionsStringifier::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSTestCEReactionsStringifierPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCEReactionsStringifierConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "value", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCEReactionsStringifier_value), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCEReactionsStringifier_value) } },
    { "valueWithoutReactions", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCEReactionsStringifier_valueWithoutReactions), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCEReactionsStringifier_valueWithoutReactions) } },
    { "toString", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestCEReactionsStringifierPrototypeFunction_toString), (intptr_t) (0) } },
};

const ClassInfo JSTestCEReactionsStringifierPrototype::s_info = { "TestCEReactionsStringifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestCEReactionsStringifierPrototype) };

void JSTestCEReactionsStringifierPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestCEReactionsStringifier::info(), JSTestCEReactionsStringifierPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestCEReactionsStringifier::s_info = { "TestCEReactionsStringifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestCEReactionsStringifier) };

JSTestCEReactionsStringifier::JSTestCEReactionsStringifier(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestCEReactionsStringifier>&& impl)
    : JSDOMWrapper<TestCEReactionsStringifier>(structure, globalObject, WTFMove(impl))
{
}

void JSTestCEReactionsStringifier::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestCEReactionsStringifier>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestCEReactionsStringifier::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestCEReactionsStringifierPrototype::create(vm, &globalObject, JSTestCEReactionsStringifierPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestCEReactionsStringifier::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestCEReactionsStringifier>(vm, globalObject);
}

JSValue JSTestCEReactionsStringifier::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestCEReactionsStringifierDOMConstructor, DOMConstructorID::TestCEReactionsStringifier>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestCEReactionsStringifier::destroy(JSC::JSCell* cell)
{
    JSTestCEReactionsStringifier* thisObject = static_cast<JSTestCEReactionsStringifier*>(cell);
    thisObject->JSTestCEReactionsStringifier::~JSTestCEReactionsStringifier();
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCEReactionsStringifierConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestCEReactionsStringifierPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestCEReactionsStringifier::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsTestCEReactionsStringifier_valueGetter(JSGlobalObject& lexicalGlobalObject, JSTestCEReactionsStringifier& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLDOMString>(lexicalGlobalObject, throwScope, impl.value())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCEReactionsStringifier_value, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCEReactionsStringifier>::get<jsTestCEReactionsStringifier_valueGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSTestCEReactionsStringifier_valueSetter(JSGlobalObject& lexicalGlobalObject, JSTestCEReactionsStringifier& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    CustomElementReactionStack customElementReactionStack(lexicalGlobalObject);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLDOMString>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    invokeFunctorPropagatingExceptionIfNecessary(lexicalGlobalObject, throwScope, [&] {
        return impl.setValue(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestCEReactionsStringifier_value, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCEReactionsStringifier>::set<setJSTestCEReactionsStringifier_valueSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSValue jsTestCEReactionsStringifier_valueWithoutReactionsGetter(JSGlobalObject& lexicalGlobalObject, JSTestCEReactionsStringifier& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLDOMString>(lexicalGlobalObject, throwScope, impl.valueWithoutReactions())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestCEReactionsStringifier_valueWithoutReactions, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCEReactionsStringifier>::get<jsTestCEReactionsStringifier_valueWithoutReactionsGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, attributeName);
}

static inline bool setJSTestCEReactionsStringifier_valueWithoutReactionsSetter(JSGlobalObject& lexicalGlobalObject, JSTestCEReactionsStringifier& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    CustomElementReactionDisallowedScope customElementReactionDisallowedScope;
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLDOMString>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    invokeFunctorPropagatingExceptionIfNecessary(lexicalGlobalObject, throwScope, [&] {
        return impl.setValueWithoutReactions(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestCEReactionsStringifier_valueWithoutReactions, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue, PropertyName attributeName))
{
    return IDLAttribute<JSTestCEReactionsStringifier>::set<setJSTestCEReactionsStringifier_valueWithoutReactionsSetter>(*lexicalGlobalObject, thisValue, encodedValue, attributeName);
}

static inline JSC::EncodedJSValue jsTestCEReactionsStringifierPrototypeFunction_toStringBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestCEReactionsStringifier>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, impl.value())));
}

JSC_DEFINE_HOST_FUNCTION(jsTestCEReactionsStringifierPrototypeFunction_toString, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestCEReactionsStringifier>::call<jsTestCEReactionsStringifierPrototypeFunction_toStringBody>(*lexicalGlobalObject, *callFrame, "toString");
}

JSC::GCClient::IsoSubspace* JSTestCEReactionsStringifier::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSTestCEReactionsStringifier, UseCustomHeapCellType::No>(vm,
        [] (auto& spaces) { return spaces.m_clientSubspaceForTestCEReactionsStringifier.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForTestCEReactionsStringifier = WTFMove(space); },
        [] (auto& spaces) { return spaces.m_subspaceForTestCEReactionsStringifier.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_subspaceForTestCEReactionsStringifier = WTFMove(space); }
    );
}

void JSTestCEReactionsStringifier::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestCEReactionsStringifier*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestCEReactionsStringifierOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestCEReactionsStringifierOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestCEReactionsStringifier = static_cast<JSTestCEReactionsStringifier*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestCEReactionsStringifier->wrapped(), jsTestCEReactionsStringifier);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestCEReactionsStringifier@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore26TestCEReactionsStringifierE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestCEReactionsStringifier>&& impl)
{

    if constexpr (std::is_polymorphic_v<TestCEReactionsStringifier>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7TestCEReactionsStringifier@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore26TestCEReactionsStringifierE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // TestCEReactionsStringifier has subclasses. If TestCEReactionsStringifier has subclasses that get passed
        // to toJS() we currently require TestCEReactionsStringifier you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<TestCEReactionsStringifier>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestCEReactionsStringifier& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestCEReactionsStringifier* JSTestCEReactionsStringifier::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestCEReactionsStringifier*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
