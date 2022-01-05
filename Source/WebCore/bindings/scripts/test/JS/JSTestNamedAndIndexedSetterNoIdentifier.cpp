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
#include "JSTestNamedAndIndexedSetterNoIdentifier.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
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
#include <JavaScriptCore/PropertyNameArray.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>


namespace WebCore {
using namespace JSC;

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestNamedAndIndexedSetterNoIdentifierConstructor);

class JSTestNamedAndIndexedSetterNoIdentifierPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestNamedAndIndexedSetterNoIdentifierPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestNamedAndIndexedSetterNoIdentifierPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestNamedAndIndexedSetterNoIdentifierPrototype>(vm.heap)) JSTestNamedAndIndexedSetterNoIdentifierPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestNamedAndIndexedSetterNoIdentifierPrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestNamedAndIndexedSetterNoIdentifierPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestNamedAndIndexedSetterNoIdentifierPrototype, JSTestNamedAndIndexedSetterNoIdentifierPrototype::Base);

using JSTestNamedAndIndexedSetterNoIdentifierDOMConstructor = JSDOMConstructorNotConstructable<JSTestNamedAndIndexedSetterNoIdentifier>;

template<> const ClassInfo JSTestNamedAndIndexedSetterNoIdentifierDOMConstructor::s_info = { "TestNamedAndIndexedSetterNoIdentifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedAndIndexedSetterNoIdentifierDOMConstructor) };

template<> JSValue JSTestNamedAndIndexedSetterNoIdentifierDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestNamedAndIndexedSetterNoIdentifierDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedAndIndexedSetterNoIdentifier::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestNamedAndIndexedSetterNoIdentifier"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

/* Hash table for prototype */

static const HashTableValue JSTestNamedAndIndexedSetterNoIdentifierPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestNamedAndIndexedSetterNoIdentifierConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

const ClassInfo JSTestNamedAndIndexedSetterNoIdentifierPrototype::s_info = { "TestNamedAndIndexedSetterNoIdentifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedAndIndexedSetterNoIdentifierPrototype) };

void JSTestNamedAndIndexedSetterNoIdentifierPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestNamedAndIndexedSetterNoIdentifier::info(), JSTestNamedAndIndexedSetterNoIdentifierPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestNamedAndIndexedSetterNoIdentifier::s_info = { "TestNamedAndIndexedSetterNoIdentifier", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestNamedAndIndexedSetterNoIdentifier) };

JSTestNamedAndIndexedSetterNoIdentifier::JSTestNamedAndIndexedSetterNoIdentifier(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestNamedAndIndexedSetterNoIdentifier>&& impl)
    : JSDOMWrapper<TestNamedAndIndexedSetterNoIdentifier>(structure, globalObject, WTFMove(impl))
{
}

void JSTestNamedAndIndexedSetterNoIdentifier::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestNamedAndIndexedSetterNoIdentifier>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestNamedAndIndexedSetterNoIdentifier::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestNamedAndIndexedSetterNoIdentifierPrototype::create(vm, &globalObject, JSTestNamedAndIndexedSetterNoIdentifierPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestNamedAndIndexedSetterNoIdentifier::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestNamedAndIndexedSetterNoIdentifier>(vm, globalObject);
}

JSValue JSTestNamedAndIndexedSetterNoIdentifier::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedAndIndexedSetterNoIdentifierDOMConstructor, DOMConstructorID::TestNamedAndIndexedSetterNoIdentifier>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestNamedAndIndexedSetterNoIdentifier::destroy(JSC::JSCell* cell)
{
    JSTestNamedAndIndexedSetterNoIdentifier* thisObject = static_cast<JSTestNamedAndIndexedSetterNoIdentifier*>(cell);
    thisObject->JSTestNamedAndIndexedSetterNoIdentifier::~JSTestNamedAndIndexedSetterNoIdentifier();
}

bool JSTestNamedAndIndexedSetterNoIdentifier::getOwnPropertySlot(JSObject* object, JSGlobalObject* lexicalGlobalObject, PropertyName propertyName, PropertySlot& slot)
{
    auto throwScope = DECLARE_THROW_SCOPE(JSC::getVM(lexicalGlobalObject));
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    if (auto index = parseIndex(propertyName)) {
        if (index.value() < thisObject->wrapped().length()) {
            auto value = toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, thisObject->wrapped().item(index.value()));
            RETURN_IF_EXCEPTION(throwScope, false);
            slot.setValue(thisObject, static_cast<unsigned>(0), value);
            return true;
        }
        return JSObject::getOwnPropertySlot(object, lexicalGlobalObject, propertyName, slot);
    }
    using GetterIDLType = IDLDOMString;
    auto getterFunctor = visibleNamedPropertyItemAccessorFunctor<GetterIDLType, JSTestNamedAndIndexedSetterNoIdentifier>([] (JSTestNamedAndIndexedSetterNoIdentifier& thisObject, PropertyName propertyName) -> decltype(auto) {
        return thisObject.wrapped().namedItem(propertyNameToAtomString(propertyName));
    });
    if (auto namedProperty = accessVisibleNamedProperty<LegacyOverrideBuiltIns::No>(*lexicalGlobalObject, *thisObject, propertyName, getterFunctor)) {
        auto value = toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, WTFMove(namedProperty.value()));
        RETURN_IF_EXCEPTION(throwScope, false);
        slot.setValue(thisObject, static_cast<unsigned>(0), value);
        return true;
    }
    return JSObject::getOwnPropertySlot(object, lexicalGlobalObject, propertyName, slot);
}

bool JSTestNamedAndIndexedSetterNoIdentifier::getOwnPropertySlotByIndex(JSObject* object, JSGlobalObject* lexicalGlobalObject, unsigned index, PropertySlot& slot)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    if (LIKELY(index <= MAX_ARRAY_INDEX)) {
        if (index < thisObject->wrapped().length()) {
            auto value = toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, thisObject->wrapped().item(index));
            RETURN_IF_EXCEPTION(throwScope, false);
            slot.setValue(thisObject, static_cast<unsigned>(0), value);
            return true;
        }
        return JSObject::getOwnPropertySlotByIndex(object, lexicalGlobalObject, index, slot);
    }
    auto propertyName = Identifier::from(vm, index);
    using GetterIDLType = IDLDOMString;
    auto getterFunctor = visibleNamedPropertyItemAccessorFunctor<GetterIDLType, JSTestNamedAndIndexedSetterNoIdentifier>([] (JSTestNamedAndIndexedSetterNoIdentifier& thisObject, PropertyName propertyName) -> decltype(auto) {
        return thisObject.wrapped().namedItem(propertyNameToAtomString(propertyName));
    });
    if (auto namedProperty = accessVisibleNamedProperty<LegacyOverrideBuiltIns::No>(*lexicalGlobalObject, *thisObject, propertyName, getterFunctor)) {
        auto value = toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, WTFMove(namedProperty.value()));
        RETURN_IF_EXCEPTION(throwScope, false);
        slot.setValue(thisObject, static_cast<unsigned>(0), value);
        return true;
    }
    return JSObject::getOwnPropertySlotByIndex(object, lexicalGlobalObject, index, slot);
}

void JSTestNamedAndIndexedSetterNoIdentifier::getOwnPropertyNames(JSObject* object, JSGlobalObject* lexicalGlobalObject, PropertyNameArray& propertyNames, DontEnumPropertiesMode mode)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(object, info());
    for (unsigned i = 0, count = thisObject->wrapped().length(); i < count; ++i)
        propertyNames.add(Identifier::from(vm, i));
    for (auto& propertyName : thisObject->wrapped().supportedPropertyNames())
        propertyNames.add(Identifier::fromString(vm, propertyName));
    JSObject::getOwnPropertyNames(object, lexicalGlobalObject, propertyNames, mode);
}

bool JSTestNamedAndIndexedSetterNoIdentifier::put(JSCell* cell, JSGlobalObject* lexicalGlobalObject, PropertyName propertyName, JSValue value, PutPropertySlot& putPropertySlot)
{
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    if (UNLIKELY(thisObject != putPropertySlot.thisValue()))
        return JSObject::put(thisObject, lexicalGlobalObject, propertyName, value, putPropertySlot);
    auto throwScope = DECLARE_THROW_SCOPE(lexicalGlobalObject->vm());

    if (auto index = parseIndex(propertyName)) {
        auto nativeValue = convert<IDLDOMString>(*lexicalGlobalObject, value);
        RETURN_IF_EXCEPTION(throwScope, true);
        invokeFunctorPropagatingExceptionIfNecessary(*lexicalGlobalObject, throwScope, [&] { return thisObject->wrapped().setItem(index.value(), WTFMove(nativeValue)); });
        return true;
    }

    if (!propertyName.isSymbol()) {
        PropertySlot slot { thisObject, PropertySlot::InternalMethodType::VMInquiry, &lexicalGlobalObject->vm() };
        JSValue prototype = thisObject->getPrototypeDirect(JSC::getVM(lexicalGlobalObject));
        bool found = prototype.isObject() && asObject(prototype)->getPropertySlot(lexicalGlobalObject, propertyName, slot);
        slot.disallowVMEntry.reset();
        RETURN_IF_EXCEPTION(throwScope, false);
        if (!found) {
            auto nativeValue = convert<IDLDOMString>(*lexicalGlobalObject, value);
            RETURN_IF_EXCEPTION(throwScope, true);
            invokeFunctorPropagatingExceptionIfNecessary(*lexicalGlobalObject, throwScope, [&] { return thisObject->wrapped().setNamedItem(propertyNameToString(propertyName), WTFMove(nativeValue)); });
            return true;
        }
    }

    throwScope.assertNoException();
    RELEASE_AND_RETURN(throwScope, JSObject::put(thisObject, lexicalGlobalObject, propertyName, value, putPropertySlot));
}

bool JSTestNamedAndIndexedSetterNoIdentifier::putByIndex(JSCell* cell, JSGlobalObject* lexicalGlobalObject, unsigned index, JSValue value, bool shouldThrow)
{
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);

    if (LIKELY(index <= MAX_ARRAY_INDEX)) {
        auto nativeValue = convert<IDLDOMString>(*lexicalGlobalObject, value);
        RETURN_IF_EXCEPTION(throwScope, true);
        invokeFunctorPropagatingExceptionIfNecessary(*lexicalGlobalObject, throwScope, [&] { return thisObject->wrapped().setItem(index, WTFMove(nativeValue)); });
        return true;
    }

    auto propertyName = Identifier::from(vm, index);
    PropertySlot slot { thisObject, PropertySlot::InternalMethodType::VMInquiry, &vm };
    JSValue prototype = thisObject->getPrototypeDirect(vm);
    bool found = prototype.isObject() && asObject(prototype)->getPropertySlot(lexicalGlobalObject, propertyName, slot);
    slot.disallowVMEntry.reset();
    RETURN_IF_EXCEPTION(throwScope, false);
    if (!found) {
        auto nativeValue = convert<IDLDOMString>(*lexicalGlobalObject, value);
        RETURN_IF_EXCEPTION(throwScope, true);
        invokeFunctorPropagatingExceptionIfNecessary(*lexicalGlobalObject, throwScope, [&] { return thisObject->wrapped().setNamedItem(propertyNameToString(propertyName), WTFMove(nativeValue)); });
        return true;
    }

    throwScope.assertNoException();
    RELEASE_AND_RETURN(throwScope, JSObject::putByIndex(cell, lexicalGlobalObject, index, value, shouldThrow));
}

bool JSTestNamedAndIndexedSetterNoIdentifier::defineOwnProperty(JSObject* object, JSGlobalObject* lexicalGlobalObject, PropertyName propertyName, const PropertyDescriptor& propertyDescriptor, bool shouldThrow)
{
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    auto throwScope = DECLARE_THROW_SCOPE(lexicalGlobalObject->vm());

    if (auto index = parseIndex(propertyName)) {
        if (!propertyDescriptor.isDataDescriptor())
            return false;
        auto nativeValue = convert<IDLDOMString>(*lexicalGlobalObject, propertyDescriptor.value());
        RETURN_IF_EXCEPTION(throwScope, true);
        invokeFunctorPropagatingExceptionIfNecessary(*lexicalGlobalObject, throwScope, [&] { return thisObject->wrapped().setItem(index.value(), WTFMove(nativeValue)); });
        return true;
    }

    if (!propertyName.isSymbol()) {
        PropertySlot slot { thisObject, PropertySlot::InternalMethodType::VMInquiry, &lexicalGlobalObject->vm() };
        bool found = JSObject::getOwnPropertySlot(thisObject, lexicalGlobalObject, propertyName, slot);
        slot.disallowVMEntry.reset();
        RETURN_IF_EXCEPTION(throwScope, false);
        if (!found) {
            if (!propertyDescriptor.isDataDescriptor())
                return false;
            auto nativeValue = convert<IDLDOMString>(*lexicalGlobalObject, propertyDescriptor.value());
            RETURN_IF_EXCEPTION(throwScope, true);
            invokeFunctorPropagatingExceptionIfNecessary(*lexicalGlobalObject, throwScope, [&] { return thisObject->wrapped().setNamedItem(propertyNameToString(propertyName), WTFMove(nativeValue)); });
            return true;
        }
    }

    PropertyDescriptor newPropertyDescriptor = propertyDescriptor;
    newPropertyDescriptor.setConfigurable(true);
    throwScope.release();
    return JSObject::defineOwnProperty(object, lexicalGlobalObject, propertyName, newPropertyDescriptor, shouldThrow);
}

JSC_DEFINE_CUSTOM_GETTER(jsTestNamedAndIndexedSetterNoIdentifierConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestNamedAndIndexedSetterNoIdentifierPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestNamedAndIndexedSetterNoIdentifier::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::IsoSubspace* JSTestNamedAndIndexedSetterNoIdentifier::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestNamedAndIndexedSetterNoIdentifier.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestNamedAndIndexedSetterNoIdentifier> || !JSTestNamedAndIndexedSetterNoIdentifier::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestNamedAndIndexedSetterNoIdentifier>)
        spaces.m_subspaceForTestNamedAndIndexedSetterNoIdentifier = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestNamedAndIndexedSetterNoIdentifier);
    else
        spaces.m_subspaceForTestNamedAndIndexedSetterNoIdentifier = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestNamedAndIndexedSetterNoIdentifier);
    auto* space = spaces.m_subspaceForTestNamedAndIndexedSetterNoIdentifier.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    void (*myVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSTestNamedAndIndexedSetterNoIdentifier::visitOutputConstraints;
    void (*jsCellVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSC::JSCell::visitOutputConstraints;
    if (myVisitOutputConstraint != jsCellVisitOutputConstraint)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestNamedAndIndexedSetterNoIdentifier::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestNamedAndIndexedSetterNoIdentifier*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestNamedAndIndexedSetterNoIdentifierOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestNamedAndIndexedSetterNoIdentifierOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestNamedAndIndexedSetterNoIdentifier = static_cast<JSTestNamedAndIndexedSetterNoIdentifier*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestNamedAndIndexedSetterNoIdentifier->wrapped(), jsTestNamedAndIndexedSetterNoIdentifier);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestNamedAndIndexedSetterNoIdentifier@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore37TestNamedAndIndexedSetterNoIdentifierE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestNamedAndIndexedSetterNoIdentifier>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
    void* expectedVTablePointer = __identifier("??_7TestNamedAndIndexedSetterNoIdentifier@WebCore@@6B@");
#else
    void* expectedVTablePointer = &_ZTVN7WebCore37TestNamedAndIndexedSetterNoIdentifierE[2];
#endif

    // If this fails TestNamedAndIndexedSetterNoIdentifier does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestNamedAndIndexedSetterNoIdentifier>::value, "TestNamedAndIndexedSetterNoIdentifier is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestNamedAndIndexedSetterNoIdentifier has subclasses. If TestNamedAndIndexedSetterNoIdentifier has subclasses that get passed
    // to toJS() we currently require TestNamedAndIndexedSetterNoIdentifier you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestNamedAndIndexedSetterNoIdentifier>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestNamedAndIndexedSetterNoIdentifier& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestNamedAndIndexedSetterNoIdentifier* JSTestNamedAndIndexedSetterNoIdentifier::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestNamedAndIndexedSetterNoIdentifier*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
