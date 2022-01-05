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
#include "JSServiceWorkerGlobalScope.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObjectInlines.h"
#include "JSDOMWrapperCache.h"
#include "JSServiceWorkerGlobalScope.h"
#include "ScriptExecutionContext.h"
#include "ServiceWorkerGlobalScope.h"
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

static JSC_DECLARE_CUSTOM_GETTER(jsServiceWorkerGlobalScopeConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsServiceWorkerGlobalScope_ServiceWorkerGlobalScopeConstructor);

using JSServiceWorkerGlobalScopeDOMConstructor = JSDOMConstructorNotConstructable<JSServiceWorkerGlobalScope>;

/* Hash table */

static const struct CompactHashIndex JSServiceWorkerGlobalScopeTableIndex[2] = {
    { -1, -1 },
    { 0, -1 },
};


static const HashTableValue JSServiceWorkerGlobalScopeTableValues[] =
{
    { "ServiceWorkerGlobalScope", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsServiceWorkerGlobalScope_ServiceWorkerGlobalScopeConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

static const HashTable JSServiceWorkerGlobalScopeTable = { 1, 1, true, JSServiceWorkerGlobalScope::info(), JSServiceWorkerGlobalScopeTableValues, JSServiceWorkerGlobalScopeTableIndex };
template<> const ClassInfo JSServiceWorkerGlobalScopeDOMConstructor::s_info = { "ServiceWorkerGlobalScope", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSServiceWorkerGlobalScopeDOMConstructor) };

template<> JSValue JSServiceWorkerGlobalScopeDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSWorkerGlobalScope::getConstructor(vm, &globalObject);
}

template<> void JSServiceWorkerGlobalScopeDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, globalObject.getPrototypeDirect(vm), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "ServiceWorkerGlobalScope"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

/* Hash table for prototype */

static const struct CompactHashIndex JSServiceWorkerGlobalScopePrototypeTableIndex[2] = {
    { -1, -1 },
    { 0, -1 },
};


static const HashTableValue JSServiceWorkerGlobalScopePrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsServiceWorkerGlobalScopeConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
};

static const HashTable JSServiceWorkerGlobalScopePrototypeTable = { 1, 1, true, JSServiceWorkerGlobalScope::info(), JSServiceWorkerGlobalScopePrototypeTableValues, JSServiceWorkerGlobalScopePrototypeTableIndex };
const ClassInfo JSServiceWorkerGlobalScopePrototype::s_info = { "ServiceWorkerGlobalScope", &Base::s_info, &JSServiceWorkerGlobalScopePrototypeTable, nullptr, CREATE_METHOD_TABLE(JSServiceWorkerGlobalScopePrototype) };

void JSServiceWorkerGlobalScopePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSServiceWorkerGlobalScope::info(), JSServiceWorkerGlobalScopePrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSServiceWorkerGlobalScope::s_info = { "ServiceWorkerGlobalScope", &Base::s_info, &JSServiceWorkerGlobalScopeTable, nullptr, CREATE_METHOD_TABLE(JSServiceWorkerGlobalScope) };

JSServiceWorkerGlobalScope::JSServiceWorkerGlobalScope(VM& vm, Structure* structure, Ref<ServiceWorkerGlobalScope>&& impl)
    : JSWorkerGlobalScope(vm, structure, WTFMove(impl))
{
}

void JSServiceWorkerGlobalScope::finishCreation(VM& vm, JSProxy* proxy)
{
    Base::finishCreation(vm, proxy);

    static_assert(!std::is_base_of<ActiveDOMObject, ServiceWorkerGlobalScope>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSValue JSServiceWorkerGlobalScope::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSServiceWorkerGlobalScopeDOMConstructor, DOMConstructorID::ServiceWorkerGlobalScope>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSC_DEFINE_CUSTOM_GETTER(jsServiceWorkerGlobalScopeConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSServiceWorkerGlobalScopePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSServiceWorkerGlobalScope::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsServiceWorkerGlobalScope_ServiceWorkerGlobalScopeConstructorGetter(JSGlobalObject& lexicalGlobalObject, JSServiceWorkerGlobalScope& thisObject)
{
    UNUSED_PARAM(lexicalGlobalObject);
    return JSServiceWorkerGlobalScope::getConstructor(JSC::getVM(&lexicalGlobalObject), &thisObject);
}

JSC_DEFINE_CUSTOM_GETTER(jsServiceWorkerGlobalScope_ServiceWorkerGlobalScopeConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName attributeName))
{
    return IDLAttribute<JSServiceWorkerGlobalScope>::get<jsServiceWorkerGlobalScope_ServiceWorkerGlobalScopeConstructorGetter>(*lexicalGlobalObject, thisValue, attributeName);
}

JSC::IsoSubspace* JSServiceWorkerGlobalScope::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForServiceWorkerGlobalScope.get())
        return space;
    spaces.m_subspaceForServiceWorkerGlobalScope = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, clientData.m_heapCellTypeForJSServiceWorkerGlobalScope.get(), JSServiceWorkerGlobalScope);
    auto* space = spaces.m_subspaceForServiceWorkerGlobalScope.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    void (*myVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSServiceWorkerGlobalScope::visitOutputConstraints;
    void (*jsCellVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSC::JSCell::visitOutputConstraints;
    if (myVisitOutputConstraint != jsCellVisitOutputConstraint)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSServiceWorkerGlobalScope::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSServiceWorkerGlobalScope*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}


}
