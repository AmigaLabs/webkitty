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
#include "JSTestDefaultToJSONIndirectInheritance.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
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

static JSC_DECLARE_CUSTOM_GETTER(jsTestDefaultToJSONIndirectInheritanceConstructor);

class JSTestDefaultToJSONIndirectInheritancePrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestDefaultToJSONIndirectInheritancePrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestDefaultToJSONIndirectInheritancePrototype* ptr = new (NotNull, JSC::allocateCell<JSTestDefaultToJSONIndirectInheritancePrototype>(vm.heap)) JSTestDefaultToJSONIndirectInheritancePrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestDefaultToJSONIndirectInheritancePrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestDefaultToJSONIndirectInheritancePrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestDefaultToJSONIndirectInheritancePrototype, JSTestDefaultToJSONIndirectInheritancePrototype::Base);

using JSTestDefaultToJSONIndirectInheritanceDOMConstructor = JSDOMConstructorNotConstructable<JSTestDefaultToJSONIndirectInheritance>;

template<> JSValue JSTestDefaultToJSONIndirectInheritanceDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSTestDefaultToJSONInherit::getConstructor(vm, &globalObject);
}

template<> void JSTestDefaultToJSONIndirectInheritanceDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestDefaultToJSONIndirectInheritance::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestDefaultToJSONIndirectInheritance"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestDefaultToJSONIndirectInheritanceDOMConstructor::s_info = { "TestDefaultToJSONIndirectInheritance", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDefaultToJSONIndirectInheritanceDOMConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestDefaultToJSONIndirectInheritancePrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestDefaultToJSONIndirectInheritanceConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

const ClassInfo JSTestDefaultToJSONIndirectInheritancePrototype::s_info = { "TestDefaultToJSONIndirectInheritance", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDefaultToJSONIndirectInheritancePrototype) };

void JSTestDefaultToJSONIndirectInheritancePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestDefaultToJSONIndirectInheritance::info(), JSTestDefaultToJSONIndirectInheritancePrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestDefaultToJSONIndirectInheritance::s_info = { "TestDefaultToJSONIndirectInheritance", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDefaultToJSONIndirectInheritance) };

JSTestDefaultToJSONIndirectInheritance::JSTestDefaultToJSONIndirectInheritance(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestDefaultToJSONIndirectInheritance>&& impl)
    : JSTestDefaultToJSONInherit(structure, globalObject, WTFMove(impl))
{
}

void JSTestDefaultToJSONIndirectInheritance::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestDefaultToJSONIndirectInheritance>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestDefaultToJSONIndirectInheritance::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestDefaultToJSONIndirectInheritancePrototype::create(vm, &globalObject, JSTestDefaultToJSONIndirectInheritancePrototype::createStructure(vm, &globalObject, JSTestDefaultToJSONInherit::prototype(vm, globalObject)));
}

JSObject* JSTestDefaultToJSONIndirectInheritance::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestDefaultToJSONIndirectInheritance>(vm, globalObject);
}

JSValue JSTestDefaultToJSONIndirectInheritance::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestDefaultToJSONIndirectInheritanceDOMConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestDefaultToJSONIndirectInheritanceConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestDefaultToJSONIndirectInheritancePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestDefaultToJSONIndirectInheritance::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

JSC::IsoSubspace* JSTestDefaultToJSONIndirectInheritance::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestDefaultToJSONIndirectInheritance.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestDefaultToJSONIndirectInheritance> || !JSTestDefaultToJSONIndirectInheritance::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestDefaultToJSONIndirectInheritance>)
        spaces.m_subspaceForTestDefaultToJSONIndirectInheritance = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestDefaultToJSONIndirectInheritance);
    else
        spaces.m_subspaceForTestDefaultToJSONIndirectInheritance = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestDefaultToJSONIndirectInheritance);
    auto* space = spaces.m_subspaceForTestDefaultToJSONIndirectInheritance.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    void (*myVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSTestDefaultToJSONIndirectInheritance::visitOutputConstraints;
    void (*jsCellVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSC::JSCell::visitOutputConstraints;
    if (myVisitOutputConstraint != jsCellVisitOutputConstraint)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestDefaultToJSONIndirectInheritance::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestDefaultToJSONIndirectInheritance*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}


}
