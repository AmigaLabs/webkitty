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
#include "JSTestStringifierNamedOperation.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
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

static JSC_DECLARE_HOST_FUNCTION(jsTestStringifierNamedOperationPrototypeFunction_identifier);
static JSC_DECLARE_HOST_FUNCTION(jsTestStringifierNamedOperationPrototypeFunction_toString);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestStringifierNamedOperationConstructor);

class JSTestStringifierNamedOperationPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestStringifierNamedOperationPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestStringifierNamedOperationPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestStringifierNamedOperationPrototype>(vm)) JSTestStringifierNamedOperationPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestStringifierNamedOperationPrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestStringifierNamedOperationPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestStringifierNamedOperationPrototype, JSTestStringifierNamedOperationPrototype::Base);

using JSTestStringifierNamedOperationDOMConstructor = JSDOMConstructorNotConstructable<JSTestStringifierNamedOperation>;

template<> const ClassInfo JSTestStringifierNamedOperationDOMConstructor::s_info = { "TestStringifierNamedOperation", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestStringifierNamedOperationDOMConstructor) };

template<> JSValue JSTestStringifierNamedOperationDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestStringifierNamedOperationDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "TestStringifierNamedOperation"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSTestStringifierNamedOperation::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSTestStringifierNamedOperationPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestStringifierNamedOperationConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "identifier", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestStringifierNamedOperationPrototypeFunction_identifier), (intptr_t) (0) } },
    { "toString", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestStringifierNamedOperationPrototypeFunction_toString), (intptr_t) (0) } },
};

const ClassInfo JSTestStringifierNamedOperationPrototype::s_info = { "TestStringifierNamedOperation", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestStringifierNamedOperationPrototype) };

void JSTestStringifierNamedOperationPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestStringifierNamedOperation::info(), JSTestStringifierNamedOperationPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestStringifierNamedOperation::s_info = { "TestStringifierNamedOperation", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestStringifierNamedOperation) };

JSTestStringifierNamedOperation::JSTestStringifierNamedOperation(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestStringifierNamedOperation>&& impl)
    : JSDOMWrapper<TestStringifierNamedOperation>(structure, globalObject, WTFMove(impl))
{
}

void JSTestStringifierNamedOperation::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestStringifierNamedOperation>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestStringifierNamedOperation::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestStringifierNamedOperationPrototype::create(vm, &globalObject, JSTestStringifierNamedOperationPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestStringifierNamedOperation::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestStringifierNamedOperation>(vm, globalObject);
}

JSValue JSTestStringifierNamedOperation::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestStringifierNamedOperationDOMConstructor, DOMConstructorID::TestStringifierNamedOperation>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestStringifierNamedOperation::destroy(JSC::JSCell* cell)
{
    JSTestStringifierNamedOperation* thisObject = static_cast<JSTestStringifierNamedOperation*>(cell);
    thisObject->JSTestStringifierNamedOperation::~JSTestStringifierNamedOperation();
}

JSC_DEFINE_CUSTOM_GETTER(jsTestStringifierNamedOperationConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestStringifierNamedOperationPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestStringifierNamedOperation::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSC::EncodedJSValue jsTestStringifierNamedOperationPrototypeFunction_identifierBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestStringifierNamedOperation>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, impl.identifier())));
}

JSC_DEFINE_HOST_FUNCTION(jsTestStringifierNamedOperationPrototypeFunction_identifier, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestStringifierNamedOperation>::call<jsTestStringifierNamedOperationPrototypeFunction_identifierBody>(*lexicalGlobalObject, *callFrame, "identifier");
}

static inline JSC::EncodedJSValue jsTestStringifierNamedOperationPrototypeFunction_toStringBody(JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame, typename IDLOperation<JSTestStringifierNamedOperation>::ClassParameter castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(callFrame);
    auto& impl = castedThis->wrapped();
    RELEASE_AND_RETURN(throwScope, JSValue::encode(toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, impl.identifier())));
}

JSC_DEFINE_HOST_FUNCTION(jsTestStringifierNamedOperationPrototypeFunction_toString, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestStringifierNamedOperation>::call<jsTestStringifierNamedOperationPrototypeFunction_toStringBody>(*lexicalGlobalObject, *callFrame, "toString");
}

JSC::GCClient::IsoSubspace* JSTestStringifierNamedOperation::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSTestStringifierNamedOperation, UseCustomHeapCellType::No>(vm,
        [] (auto& spaces) { return spaces.m_clientSubspaceForTestStringifierNamedOperation.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForTestStringifierNamedOperation = WTFMove(space); },
        [] (auto& spaces) { return spaces.m_subspaceForTestStringifierNamedOperation.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_subspaceForTestStringifierNamedOperation = WTFMove(space); }
    );
}

void JSTestStringifierNamedOperation::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestStringifierNamedOperation*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestStringifierNamedOperationOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestStringifierNamedOperationOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestStringifierNamedOperation = static_cast<JSTestStringifierNamedOperation*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestStringifierNamedOperation->wrapped(), jsTestStringifierNamedOperation);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestStringifierNamedOperation@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore29TestStringifierNamedOperationE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestStringifierNamedOperation>&& impl)
{

    if constexpr (std::is_polymorphic_v<TestStringifierNamedOperation>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7TestStringifierNamedOperation@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore29TestStringifierNamedOperationE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // TestStringifierNamedOperation has subclasses. If TestStringifierNamedOperation has subclasses that get passed
        // to toJS() we currently require TestStringifierNamedOperation you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<TestStringifierNamedOperation>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestStringifierNamedOperation& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestStringifierNamedOperation* JSTestStringifierNamedOperation::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestStringifierNamedOperation*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
