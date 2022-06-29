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
#include "JSTestNamedGetterCallWith.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMAbstractOperations.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
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

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestNamedGetterCallWithConstructor);

class JSTestNamedGetterCallWithPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestNamedGetterCallWithPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestNamedGetterCallWithPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestNamedGetterCallWithPrototype>(vm)) JSTestNamedGetterCallWithPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestNamedGetterCallWithPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestNamedGetterCallWithPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestNamedGetterCallWithPrototype, JSTestNamedGetterCallWithPrototype::Base);

using JSTestNamedGetterCallWithDOMConstructor = JSDOMConstructorNotConstructable<JSTestNamedGetterCallWith>;

template<> const ClassInfo JSTestNamedGetterCallWithDOMConstructor::s_info = { "TestNamedGetterCallWith", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedGetterCallWithDOMConstructor) };

template<> JSValue JSTestNamedGetterCallWithDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestNamedGetterCallWithDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "TestNamedGetterCallWith"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedGetterCallWith::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSTestNamedGetterCallWithPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestNamedGetterCallWithConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

const ClassInfo JSTestNamedGetterCallWithPrototype::s_info = { "TestNamedGetterCallWith", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedGetterCallWithPrototype) };

void JSTestNamedGetterCallWithPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestNamedGetterCallWith::info(), JSTestNamedGetterCallWithPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestNamedGetterCallWith::s_info = { "TestNamedGetterCallWith", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedGetterCallWith) };

JSTestNamedGetterCallWith::JSTestNamedGetterCallWith(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestNamedGetterCallWith>&& impl)
    : JSDOMWrapper<TestNamedGetterCallWith>(structure, globalObject, WTFMove(impl))
{
}

void JSTestNamedGetterCallWith::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestNamedGetterCallWith>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestNamedGetterCallWith::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestNamedGetterCallWithPrototype::create(vm, &globalObject, JSTestNamedGetterCallWithPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestNamedGetterCallWith::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestNamedGetterCallWith>(vm, globalObject);
}

JSValue JSTestNamedGetterCallWith::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedGetterCallWithDOMConstructor, DOMConstructorID::TestNamedGetterCallWith>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestNamedGetterCallWith::destroy(JSC::JSCell* cell)
{
    JSTestNamedGetterCallWith* thisObject = static_cast<JSTestNamedGetterCallWith*>(cell);
    thisObject->JSTestNamedGetterCallWith::~JSTestNamedGetterCallWith();
}

bool JSTestNamedGetterCallWith::getOwnPropertySlot(JSObject* object, JSGlobalObject* lexicalGlobalObject, PropertyName propertyName, PropertySlot& slot)
{
    auto throwScope = DECLARE_THROW_SCOPE(JSC::getVM(lexicalGlobalObject));
    auto* thisObject = jsCast<JSTestNamedGetterCallWith*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    using GetterIDLType = IDLDOMString;
    auto getterFunctor = visibleNamedPropertyItemAccessorFunctor<GetterIDLType, JSTestNamedGetterCallWith>([] (JSTestNamedGetterCallWith& thisObject, PropertyName propertyName) -> decltype(auto) {
        return thisObject.wrapped().namedItem(worldForDOMObject(thisObject), propertyNameToAtomString(propertyName));
    });
    if (auto namedProperty = accessVisibleNamedProperty<LegacyOverrideBuiltIns::No>(*lexicalGlobalObject, *thisObject, propertyName, getterFunctor)) {
        auto value = toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, WTFMove(namedProperty.value()));
        RETURN_IF_EXCEPTION(throwScope, false);
        slot.setValue(thisObject, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly), value);
        return true;
    }
    return JSObject::getOwnPropertySlot(object, lexicalGlobalObject, propertyName, slot);
}

bool JSTestNamedGetterCallWith::getOwnPropertySlotByIndex(JSObject* object, JSGlobalObject* lexicalGlobalObject, unsigned index, PropertySlot& slot)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* thisObject = jsCast<JSTestNamedGetterCallWith*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    auto propertyName = Identifier::from(vm, index);
    using GetterIDLType = IDLDOMString;
    auto getterFunctor = visibleNamedPropertyItemAccessorFunctor<GetterIDLType, JSTestNamedGetterCallWith>([] (JSTestNamedGetterCallWith& thisObject, PropertyName propertyName) -> decltype(auto) {
        return thisObject.wrapped().namedItem(worldForDOMObject(thisObject), propertyNameToAtomString(propertyName));
    });
    if (auto namedProperty = accessVisibleNamedProperty<LegacyOverrideBuiltIns::No>(*lexicalGlobalObject, *thisObject, propertyName, getterFunctor)) {
        auto value = toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, WTFMove(namedProperty.value()));
        RETURN_IF_EXCEPTION(throwScope, false);
        slot.setValue(thisObject, static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly), value);
        return true;
    }
    return JSObject::getOwnPropertySlotByIndex(object, lexicalGlobalObject, index, slot);
}

void JSTestNamedGetterCallWith::getOwnPropertyNames(JSObject* object, JSGlobalObject* lexicalGlobalObject, PropertyNameArray& propertyNames, DontEnumPropertiesMode mode)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto* thisObject = jsCast<JSTestNamedGetterCallWith*>(object);
    ASSERT_GC_OBJECT_INHERITS(object, info());
    for (auto& propertyName : thisObject->wrapped().supportedPropertyNames())
        propertyNames.add(Identifier::fromString(vm, propertyName));
    JSObject::getOwnPropertyNames(object, lexicalGlobalObject, propertyNames, mode);
}

JSC_DEFINE_CUSTOM_GETTER(jsTestNamedGetterCallWithConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestNamedGetterCallWithPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestNamedGetterCallWith::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::GCClient::IsoSubspace* JSTestNamedGetterCallWith::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSTestNamedGetterCallWith, UseCustomHeapCellType::No>(vm,
        [] (auto& spaces) { return spaces.m_clientSubspaceForTestNamedGetterCallWith.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForTestNamedGetterCallWith = WTFMove(space); },
        [] (auto& spaces) { return spaces.m_subspaceForTestNamedGetterCallWith.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_subspaceForTestNamedGetterCallWith = WTFMove(space); }
    );
}

void JSTestNamedGetterCallWith::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestNamedGetterCallWith*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestNamedGetterCallWithOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestNamedGetterCallWithOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestNamedGetterCallWith = static_cast<JSTestNamedGetterCallWith*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestNamedGetterCallWith->wrapped(), jsTestNamedGetterCallWith);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestNamedGetterCallWith@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore23TestNamedGetterCallWithE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestNamedGetterCallWith>&& impl)
{

    if constexpr (std::is_polymorphic_v<TestNamedGetterCallWith>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7TestNamedGetterCallWith@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore23TestNamedGetterCallWithE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // TestNamedGetterCallWith has subclasses. If TestNamedGetterCallWith has subclasses that get passed
        // to toJS() we currently require TestNamedGetterCallWith you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<TestNamedGetterCallWith>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestNamedGetterCallWith& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestNamedGetterCallWith* JSTestNamedGetterCallWith::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestNamedGetterCallWith*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
