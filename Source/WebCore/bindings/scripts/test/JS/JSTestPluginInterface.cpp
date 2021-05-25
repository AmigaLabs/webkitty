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
#include "JSTestPluginInterface.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include "JSPluginElementFunctions.h"
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

static JSC_DECLARE_CUSTOM_GETTER(jsTestPluginInterfaceConstructor);

class JSTestPluginInterfacePrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestPluginInterfacePrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestPluginInterfacePrototype* ptr = new (NotNull, JSC::allocateCell<JSTestPluginInterfacePrototype>(vm.heap)) JSTestPluginInterfacePrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestPluginInterfacePrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestPluginInterfacePrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestPluginInterfacePrototype, JSTestPluginInterfacePrototype::Base);

using JSTestPluginInterfaceDOMConstructor = JSDOMConstructorNotConstructable<JSTestPluginInterface>;

template<> JSValue JSTestPluginInterfaceDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestPluginInterfaceDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestPluginInterface::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestPluginInterface"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestPluginInterfaceDOMConstructor::s_info = { "TestPluginInterface", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestPluginInterfaceDOMConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestPluginInterfacePrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestPluginInterfaceConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

const ClassInfo JSTestPluginInterfacePrototype::s_info = { "TestPluginInterface", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestPluginInterfacePrototype) };

void JSTestPluginInterfacePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestPluginInterface::info(), JSTestPluginInterfacePrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestPluginInterface::s_info = { "TestPluginInterface", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestPluginInterface) };

JSTestPluginInterface::JSTestPluginInterface(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestPluginInterface>&& impl)
    : JSDOMWrapper<TestPluginInterface>(structure, globalObject, WTFMove(impl))
{
}

void JSTestPluginInterface::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestPluginInterface>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestPluginInterface::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestPluginInterfacePrototype::create(vm, &globalObject, JSTestPluginInterfacePrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestPluginInterface::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestPluginInterface>(vm, globalObject);
}

JSValue JSTestPluginInterface::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestPluginInterfaceDOMConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestPluginInterface::destroy(JSC::JSCell* cell)
{
    JSTestPluginInterface* thisObject = static_cast<JSTestPluginInterface*>(cell);
    thisObject->JSTestPluginInterface::~JSTestPluginInterface();
}

bool JSTestPluginInterface::getOwnPropertySlot(JSObject* object, JSGlobalObject* lexicalGlobalObject, PropertyName propertyName, PropertySlot& slot)
{
    auto* thisObject = jsCast<JSTestPluginInterface*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    if (pluginElementCustomGetOwnPropertySlot(thisObject, lexicalGlobalObject, propertyName, slot))
        return true;
    ASSERT(slot.isTaintedByOpaqueObject());
    if (slot.isVMInquiry())
        return false;
    return JSObject::getOwnPropertySlot(object, lexicalGlobalObject, propertyName, slot);
}

bool JSTestPluginInterface::getOwnPropertySlotByIndex(JSObject* object, JSGlobalObject* lexicalGlobalObject, unsigned index, PropertySlot& slot)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto* thisObject = jsCast<JSTestPluginInterface*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    auto propertyName = Identifier::from(vm, index);
    if (pluginElementCustomGetOwnPropertySlot(thisObject, lexicalGlobalObject, propertyName, slot))
        return true;
    ASSERT(slot.isTaintedByOpaqueObject());
    if (slot.isVMInquiry())
        return false;
    return JSObject::getOwnPropertySlotByIndex(object, lexicalGlobalObject, index, slot);
}

bool JSTestPluginInterface::put(JSCell* cell, JSGlobalObject* lexicalGlobalObject, PropertyName propertyName, JSValue value, PutPropertySlot& putPropertySlot)
{
    auto* thisObject = jsCast<JSTestPluginInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    auto throwScope = DECLARE_THROW_SCOPE(lexicalGlobalObject->vm());

    bool putResult = false;
    bool success = pluginElementCustomPut(thisObject, lexicalGlobalObject, propertyName, value, putPropertySlot, putResult);
    RETURN_IF_EXCEPTION(throwScope, false);
    if (success)
        return putResult;

    throwScope.assertNoException();
    RELEASE_AND_RETURN(throwScope, JSObject::put(thisObject, lexicalGlobalObject, propertyName, value, putPropertySlot));
}

bool JSTestPluginInterface::putByIndex(JSCell* cell, JSGlobalObject* lexicalGlobalObject, unsigned index, JSValue value, bool shouldThrow)
{
    auto* thisObject = jsCast<JSTestPluginInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);

    auto propertyName = Identifier::from(vm, index);
    PutPropertySlot putPropertySlot(thisObject, shouldThrow);
    bool putResult = false;
    bool success = pluginElementCustomPut(thisObject, lexicalGlobalObject, propertyName, value, putPropertySlot, putResult);
    RETURN_IF_EXCEPTION(throwScope, false);
    if (success)
        return putResult;

    throwScope.assertNoException();
    RELEASE_AND_RETURN(throwScope, JSObject::putByIndex(cell, lexicalGlobalObject, index, value, shouldThrow));
}

CallData JSTestPluginInterface::getCallData(JSCell* cell)
{
    auto* thisObject = jsCast<JSTestPluginInterface*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());

    return pluginElementCustomGetCallData(thisObject);
}

JSC_DEFINE_CUSTOM_GETTER(jsTestPluginInterfaceConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestPluginInterfacePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestPluginInterface::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::IsoSubspace* JSTestPluginInterface::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestPluginInterface.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestPluginInterface> || !JSTestPluginInterface::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestPluginInterface>)
        spaces.m_subspaceForTestPluginInterface = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestPluginInterface);
    else
        spaces.m_subspaceForTestPluginInterface = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestPluginInterface);
    auto* space = spaces.m_subspaceForTestPluginInterface.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    void (*myVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSTestPluginInterface::visitOutputConstraints;
    void (*jsCellVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSC::JSCell::visitOutputConstraints;
    if (myVisitOutputConstraint != jsCellVisitOutputConstraint)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestPluginInterface::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestPluginInterface*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestPluginInterfaceOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestPluginInterfaceOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestPluginInterface = static_cast<JSTestPluginInterface*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestPluginInterface->wrapped(), jsTestPluginInterface);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestPluginInterface@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore19TestPluginInterfaceE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestPluginInterface>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
    void* expectedVTablePointer = __identifier("??_7TestPluginInterface@WebCore@@6B@");
#else
    void* expectedVTablePointer = &_ZTVN7WebCore19TestPluginInterfaceE[2];
#endif

    // If this fails TestPluginInterface does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestPluginInterface>::value, "TestPluginInterface is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestPluginInterface has subclasses. If TestPluginInterface has subclasses that get passed
    // to toJS() we currently require TestPluginInterface you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestPluginInterface>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestPluginInterface& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestPluginInterface* JSTestPluginInterface::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestPluginInterface*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
