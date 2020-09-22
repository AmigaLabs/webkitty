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
#include "JSTestClassWithJSBuiltinConstructor.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "JSDOMBinding.h"
#include "JSDOMBuiltinConstructor.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include "TestClassWithJSBuiltinConstructorBuiltins.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/FunctionPrototype.h>
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>


namespace WebCore {
using namespace JSC;

// Attributes

JSC::EncodedJSValue jsTestClassWithJSBuiltinConstructorConstructor(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestClassWithJSBuiltinConstructorConstructor(JSC::JSGlobalObject*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestClassWithJSBuiltinConstructorPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestClassWithJSBuiltinConstructorPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestClassWithJSBuiltinConstructorPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestClassWithJSBuiltinConstructorPrototype>(vm.heap)) JSTestClassWithJSBuiltinConstructorPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestClassWithJSBuiltinConstructorPrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestClassWithJSBuiltinConstructorPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestClassWithJSBuiltinConstructorPrototype, JSTestClassWithJSBuiltinConstructorPrototype::Base);

using JSTestClassWithJSBuiltinConstructorConstructor = JSDOMBuiltinConstructor<JSTestClassWithJSBuiltinConstructor>;

template<> JSValue JSTestClassWithJSBuiltinConstructorConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestClassWithJSBuiltinConstructorConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestClassWithJSBuiltinConstructor::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestClassWithJSBuiltinConstructor"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> FunctionExecutable* JSTestClassWithJSBuiltinConstructorConstructor::initializeExecutable(VM& vm)
{
    return testClassWithJSBuiltinConstructorInitializeTestClassWithJSBuiltinConstructorCodeGenerator(vm);
}

template<> const ClassInfo JSTestClassWithJSBuiltinConstructorConstructor::s_info = { "TestClassWithJSBuiltinConstructor", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestClassWithJSBuiltinConstructorConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestClassWithJSBuiltinConstructorPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestClassWithJSBuiltinConstructorConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestClassWithJSBuiltinConstructorConstructor) } },
};

const ClassInfo JSTestClassWithJSBuiltinConstructorPrototype::s_info = { "TestClassWithJSBuiltinConstructor", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestClassWithJSBuiltinConstructorPrototype) };

void JSTestClassWithJSBuiltinConstructorPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestClassWithJSBuiltinConstructor::info(), JSTestClassWithJSBuiltinConstructorPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestClassWithJSBuiltinConstructor::s_info = { "TestClassWithJSBuiltinConstructor", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestClassWithJSBuiltinConstructor) };

JSTestClassWithJSBuiltinConstructor::JSTestClassWithJSBuiltinConstructor(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestClassWithJSBuiltinConstructor>&& impl)
    : JSDOMWrapper<TestClassWithJSBuiltinConstructor>(structure, globalObject, WTFMove(impl))
{
}

void JSTestClassWithJSBuiltinConstructor::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestClassWithJSBuiltinConstructor>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestClassWithJSBuiltinConstructor::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestClassWithJSBuiltinConstructorPrototype::create(vm, &globalObject, JSTestClassWithJSBuiltinConstructorPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestClassWithJSBuiltinConstructor::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestClassWithJSBuiltinConstructor>(vm, globalObject);
}

JSValue JSTestClassWithJSBuiltinConstructor::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestClassWithJSBuiltinConstructorConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestClassWithJSBuiltinConstructor::destroy(JSC::JSCell* cell)
{
    JSTestClassWithJSBuiltinConstructor* thisObject = static_cast<JSTestClassWithJSBuiltinConstructor*>(cell);
    thisObject->JSTestClassWithJSBuiltinConstructor::~JSTestClassWithJSBuiltinConstructor();
}

EncodedJSValue jsTestClassWithJSBuiltinConstructorConstructor(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestClassWithJSBuiltinConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestClassWithJSBuiltinConstructor::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

bool setJSTestClassWithJSBuiltinConstructorConstructor(JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestClassWithJSBuiltinConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype)) {
        throwVMTypeError(lexicalGlobalObject, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return prototype->putDirect(vm, vm.propertyNames->constructor, JSValue::decode(encodedValue));
}

JSC::IsoSubspace* JSTestClassWithJSBuiltinConstructor::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestClassWithJSBuiltinConstructor.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestClassWithJSBuiltinConstructor> || !JSTestClassWithJSBuiltinConstructor::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestClassWithJSBuiltinConstructor>)
        spaces.m_subspaceForTestClassWithJSBuiltinConstructor = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestClassWithJSBuiltinConstructor);
    else
        spaces.m_subspaceForTestClassWithJSBuiltinConstructor = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestClassWithJSBuiltinConstructor);
    auto* space = spaces.m_subspaceForTestClassWithJSBuiltinConstructor.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    if (&JSTestClassWithJSBuiltinConstructor::visitOutputConstraints != &JSC::JSCell::visitOutputConstraints)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestClassWithJSBuiltinConstructor::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestClassWithJSBuiltinConstructor*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestClassWithJSBuiltinConstructorOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestClassWithJSBuiltinConstructorOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestClassWithJSBuiltinConstructor = static_cast<JSTestClassWithJSBuiltinConstructor*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestClassWithJSBuiltinConstructor->wrapped(), jsTestClassWithJSBuiltinConstructor);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestClassWithJSBuiltinConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore33TestClassWithJSBuiltinConstructorE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestClassWithJSBuiltinConstructor>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
    void* expectedVTablePointer = __identifier("??_7TestClassWithJSBuiltinConstructor@WebCore@@6B@");
#else
    void* expectedVTablePointer = &_ZTVN7WebCore33TestClassWithJSBuiltinConstructorE[2];
#endif

    // If this fails TestClassWithJSBuiltinConstructor does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestClassWithJSBuiltinConstructor>::value, "TestClassWithJSBuiltinConstructor is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestClassWithJSBuiltinConstructor has subclasses. If TestClassWithJSBuiltinConstructor has subclasses that get passed
    // to toJS() we currently require TestClassWithJSBuiltinConstructor you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestClassWithJSBuiltinConstructor>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestClassWithJSBuiltinConstructor& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestClassWithJSBuiltinConstructor* JSTestClassWithJSBuiltinConstructor::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestClassWithJSBuiltinConstructor*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
