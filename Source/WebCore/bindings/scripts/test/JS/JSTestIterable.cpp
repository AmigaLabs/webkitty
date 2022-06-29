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
#include "JSTestIterable.h"

#include "ActiveDOMObject.h"
#include "ExtendedDOMClientIsoSubspaces.h"
#include "ExtendedDOMIsoSubspaces.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMIterator.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSTestNode.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/BuiltinNames.h>
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

static JSC_DECLARE_HOST_FUNCTION(jsTestIterablePrototypeFunction_entries);
static JSC_DECLARE_HOST_FUNCTION(jsTestIterablePrototypeFunction_keys);
static JSC_DECLARE_HOST_FUNCTION(jsTestIterablePrototypeFunction_values);
static JSC_DECLARE_HOST_FUNCTION(jsTestIterablePrototypeFunction_forEach);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestIterableConstructor);

class JSTestIterablePrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestIterablePrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestIterablePrototype* ptr = new (NotNull, JSC::allocateCell<JSTestIterablePrototype>(vm)) JSTestIterablePrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestIterablePrototype, Base);
        return &vm.plainObjectSpace();
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestIterablePrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestIterablePrototype, JSTestIterablePrototype::Base);

using JSTestIterableDOMConstructor = JSDOMConstructorNotConstructable<JSTestIterable>;

template<> const ClassInfo JSTestIterableDOMConstructor::s_info = { "TestIterable", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestIterableDOMConstructor) };

template<> JSValue JSTestIterableDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestIterableDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    JSString* nameString = jsNontrivialString(vm, "TestIterable"_s);
    m_originalName.set(vm, this, nameString);
    putDirect(vm, vm.propertyNames->name, nameString, JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->prototype, JSTestIterable::prototype(vm, globalObject), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum | JSC::PropertyAttribute::DontDelete);
}

/* Hash table for prototype */

static const HashTableValue JSTestIterablePrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestIterableConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "entries", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestIterablePrototypeFunction_entries), (intptr_t) (0) } },
    { "keys", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestIterablePrototypeFunction_keys), (intptr_t) (0) } },
    { "values", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestIterablePrototypeFunction_values), (intptr_t) (0) } },
    { "forEach", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestIterablePrototypeFunction_forEach), (intptr_t) (1) } },
};

const ClassInfo JSTestIterablePrototype::s_info = { "TestIterable", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestIterablePrototype) };

void JSTestIterablePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestIterable::info(), JSTestIterablePrototypeTableValues, *this);
    putDirect(vm, vm.propertyNames->iteratorSymbol, getDirect(vm, vm.propertyNames->builtinNames().entriesPublicName()), static_cast<unsigned>(JSC::PropertyAttribute::DontEnum));
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestIterable::s_info = { "TestIterable", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestIterable) };

JSTestIterable::JSTestIterable(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestIterable>&& impl)
    : JSDOMWrapper<TestIterable>(structure, globalObject, WTFMove(impl))
{
}

void JSTestIterable::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestIterable>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestIterable::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestIterablePrototype::create(vm, &globalObject, JSTestIterablePrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestIterable::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestIterable>(vm, globalObject);
}

JSValue JSTestIterable::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestIterableDOMConstructor, DOMConstructorID::TestIterable>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestIterable::destroy(JSC::JSCell* cell)
{
    JSTestIterable* thisObject = static_cast<JSTestIterable*>(cell);
    thisObject->JSTestIterable::~JSTestIterable();
}

JSC_DEFINE_CUSTOM_GETTER(jsTestIterableConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestIterablePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestIterable::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

struct TestIterableIteratorTraits {
    static constexpr JSDOMIteratorType type = JSDOMIteratorType::Set;
    using KeyType = void;
    using ValueType = IDLInterface<TestNode>;
};

using TestIterableIteratorBase = JSDOMIteratorBase<JSTestIterable, TestIterableIteratorTraits>;
class TestIterableIterator final : public TestIterableIteratorBase {
public:
    using Base = TestIterableIteratorBase;
    DECLARE_INFO;

    template<typename, SubspaceAccess mode> static JSC::GCClient::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return WebCore::subspaceForImpl<TestIterableIterator, UseCustomHeapCellType::No>(vm,
            [] (auto& spaces) { return spaces.m_clientSubspaceForTestIterableIterator.get(); },
            [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForTestIterableIterator = WTFMove(space); },
            [] (auto& spaces) { return spaces.m_subspaceForTestIterableIterator.get(); },
            [] (auto& spaces, auto&& space) { spaces.m_subspaceForTestIterableIterator = WTFMove(space); }
        );
    }

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static TestIterableIterator* create(JSC::VM& vm, JSC::Structure* structure, JSTestIterable& iteratedObject, IterationKind kind)
    {
        auto* instance = new (NotNull, JSC::allocateCell<TestIterableIterator>(vm)) TestIterableIterator(structure, iteratedObject, kind);
        instance->finishCreation(vm);
        return instance;
    }

private:
    TestIterableIterator(JSC::Structure* structure, JSTestIterable& iteratedObject, IterationKind kind)
        : Base(structure, iteratedObject, kind)
    {
    }
};

using TestIterableIteratorPrototype = JSDOMIteratorPrototype<JSTestIterable, TestIterableIteratorTraits>;
JSC_ANNOTATE_HOST_FUNCTION(TestIterableIteratorPrototypeNext, TestIterableIteratorPrototype::next);

template<>
const JSC::ClassInfo TestIterableIteratorBase::s_info = { "TestIterable Iterator", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(TestIterableIteratorBase) };
const JSC::ClassInfo TestIterableIterator::s_info = { "TestIterable Iterator", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(TestIterableIterator) };

template<>
const JSC::ClassInfo TestIterableIteratorPrototype::s_info = { "TestIterable Iterator", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(TestIterableIteratorPrototype) };

static inline EncodedJSValue jsTestIterablePrototypeFunction_entriesCaller(JSGlobalObject*, CallFrame*, JSTestIterable* thisObject)
{
    return JSValue::encode(iteratorCreate<TestIterableIterator>(*thisObject, IterationKind::Values));
}

JSC_DEFINE_HOST_FUNCTION(jsTestIterablePrototypeFunction_entries, (JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSTestIterable>::call<jsTestIterablePrototypeFunction_entriesCaller>(*lexicalGlobalObject, *callFrame, "entries");
}

static inline EncodedJSValue jsTestIterablePrototypeFunction_keysCaller(JSGlobalObject*, CallFrame*, JSTestIterable* thisObject)
{
    return JSValue::encode(iteratorCreate<TestIterableIterator>(*thisObject, IterationKind::Keys));
}

JSC_DEFINE_HOST_FUNCTION(jsTestIterablePrototypeFunction_keys, (JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSTestIterable>::call<jsTestIterablePrototypeFunction_keysCaller>(*lexicalGlobalObject, *callFrame, "keys");
}

static inline EncodedJSValue jsTestIterablePrototypeFunction_valuesCaller(JSGlobalObject*, CallFrame*, JSTestIterable* thisObject)
{
    return JSValue::encode(iteratorCreate<TestIterableIterator>(*thisObject, IterationKind::Values));
}

JSC_DEFINE_HOST_FUNCTION(jsTestIterablePrototypeFunction_values, (JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSTestIterable>::call<jsTestIterablePrototypeFunction_valuesCaller>(*lexicalGlobalObject, *callFrame, "values");
}

static inline EncodedJSValue jsTestIterablePrototypeFunction_forEachCaller(JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame, JSTestIterable* thisObject)
{
    return JSValue::encode(iteratorForEach<TestIterableIterator>(*lexicalGlobalObject, *callFrame, *thisObject));
}

JSC_DEFINE_HOST_FUNCTION(jsTestIterablePrototypeFunction_forEach, (JSC::JSGlobalObject* lexicalGlobalObject, JSC::CallFrame* callFrame))
{
    return IDLOperation<JSTestIterable>::call<jsTestIterablePrototypeFunction_forEachCaller>(*lexicalGlobalObject, *callFrame, "forEach");
}

JSC::GCClient::IsoSubspace* JSTestIterable::subspaceForImpl(JSC::VM& vm)
{
    return WebCore::subspaceForImpl<JSTestIterable, UseCustomHeapCellType::No>(vm,
        [] (auto& spaces) { return spaces.m_clientSubspaceForTestIterable.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_clientSubspaceForTestIterable = WTFMove(space); },
        [] (auto& spaces) { return spaces.m_subspaceForTestIterable.get(); },
        [] (auto& spaces, auto&& space) { spaces.m_subspaceForTestIterable = WTFMove(space); }
    );
}

void JSTestIterable::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestIterable*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}

bool JSTestIterableOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, AbstractSlotVisitor& visitor, const char** reason)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    UNUSED_PARAM(reason);
    return false;
}

void JSTestIterableOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestIterable = static_cast<JSTestIterable*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestIterable->wrapped(), jsTestIterable);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestIterable@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore12TestIterableE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject* globalObject, Ref<TestIterable>&& impl)
{

    if constexpr (std::is_polymorphic_v<TestIterable>) {
#if ENABLE(BINDING_INTEGRITY)
        const void* actualVTablePointer = getVTablePointer(impl.ptr());
#if PLATFORM(WIN)
        void* expectedVTablePointer = __identifier("??_7TestIterable@WebCore@@6B@");
#else
        void* expectedVTablePointer = &_ZTVN7WebCore12TestIterableE[2];
#endif

        // If you hit this assertion you either have a use after free bug, or
        // TestIterable has subclasses. If TestIterable has subclasses that get passed
        // to toJS() we currently require TestIterable you to opt out of binding hardening
        // by adding the SkipVTableValidation attribute to the interface IDL definition
        RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    }
    return createWrapper<TestIterable>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestIterable& impl)
{
    return wrap(lexicalGlobalObject, globalObject, impl);
}

TestIterable* JSTestIterable::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicCast<JSTestIterable*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
