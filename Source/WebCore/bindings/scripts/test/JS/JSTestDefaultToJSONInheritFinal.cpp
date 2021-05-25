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
#include "JSTestDefaultToJSONInheritFinal.h"

#include "ActiveDOMObject.h"
#include "DOMIsoSubspaces.h"
#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNullable.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertRecord.h"
#include "JSDOMConvertSequences.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSDOMOperation.h"
#include "JSDOMWrapperCache.h"
#include "JSTestDefaultToJSONIndirectInheritance.h"
#include "JSTestDefaultToJSONInheritFinal.h"
#include "RuntimeEnabledFeatures.h"
#include "ScriptExecutionContext.h"
#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapAnalyzer.h>
#include <JavaScriptCore/JSArray.h>
#include <JavaScriptCore/JSCInlines.h>
#include <JavaScriptCore/JSDestructibleObjectHeapCellType.h>
#include <JavaScriptCore/ObjectConstructor.h>
#include <JavaScriptCore/SlotVisitorMacros.h>
#include <JavaScriptCore/SubspaceInlines.h>
#include <wtf/GetPtr.h>
#include <wtf/PointerPreparations.h>
#include <wtf/URL.h>
#include <wtf/Vector.h>

#if ENABLE(TEST_CONDITIONAL)
#include "JSDOMConvertEnumeration.h"
#include "JSTestDefaultToJSONEnum.h"
#endif


namespace WebCore {
using namespace JSC;

// Functions

static JSC_DECLARE_HOST_FUNCTION(jsTestDefaultToJSONInheritFinalPrototypeFunction_toJSON);

// Attributes

static JSC_DECLARE_CUSTOM_GETTER(jsTestDefaultToJSONInheritFinalConstructor);
static JSC_DECLARE_CUSTOM_GETTER(jsTestDefaultToJSONInheritFinal_finalLongAttributeFoo);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestDefaultToJSONInheritFinal_finalLongAttributeFoo);
static JSC_DECLARE_CUSTOM_GETTER(jsTestDefaultToJSONInheritFinal_finalLongAttributeBar);
static JSC_DECLARE_CUSTOM_SETTER(setJSTestDefaultToJSONInheritFinal_finalLongAttributeBar);

class JSTestDefaultToJSONInheritFinalPrototype final : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestDefaultToJSONInheritFinalPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestDefaultToJSONInheritFinalPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestDefaultToJSONInheritFinalPrototype>(vm.heap)) JSTestDefaultToJSONInheritFinalPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    template<typename CellType, JSC::SubspaceAccess>
    static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestDefaultToJSONInheritFinalPrototype, Base);
        return &vm.plainObjectSpace;
    }
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestDefaultToJSONInheritFinalPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};
STATIC_ASSERT_ISO_SUBSPACE_SHARABLE(JSTestDefaultToJSONInheritFinalPrototype, JSTestDefaultToJSONInheritFinalPrototype::Base);

using JSTestDefaultToJSONInheritFinalDOMConstructor = JSDOMConstructorNotConstructable<JSTestDefaultToJSONInheritFinal>;

template<> JSValue JSTestDefaultToJSONInheritFinalDOMConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSTestDefaultToJSONInherit::getConstructor(vm, &globalObject);
}

template<> void JSTestDefaultToJSONInheritFinalDOMConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestDefaultToJSONInheritFinal::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(vm, "TestDefaultToJSONInheritFinal"_s), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestDefaultToJSONInheritFinalDOMConstructor::s_info = { "TestDefaultToJSONInheritFinal", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDefaultToJSONInheritFinalDOMConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestDefaultToJSONInheritFinalPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestDefaultToJSONInheritFinalConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "finalLongAttributeFoo", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestDefaultToJSONInheritFinal_finalLongAttributeFoo), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestDefaultToJSONInheritFinal_finalLongAttributeFoo) } },
    { "finalLongAttributeBar", static_cast<unsigned>(JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestDefaultToJSONInheritFinal_finalLongAttributeBar), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestDefaultToJSONInheritFinal_finalLongAttributeBar) } },
    { "toJSON", static_cast<unsigned>(JSC::PropertyAttribute::Function), NoIntrinsic, { (intptr_t)static_cast<RawNativeFunction>(jsTestDefaultToJSONInheritFinalPrototypeFunction_toJSON), (intptr_t) (0) } },
};

const ClassInfo JSTestDefaultToJSONInheritFinalPrototype::s_info = { "TestDefaultToJSONInheritFinal", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDefaultToJSONInheritFinalPrototype) };

void JSTestDefaultToJSONInheritFinalPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestDefaultToJSONInheritFinal::info(), JSTestDefaultToJSONInheritFinalPrototypeTableValues, *this);
    JSC_TO_STRING_TAG_WITHOUT_TRANSITION();
}

const ClassInfo JSTestDefaultToJSONInheritFinal::s_info = { "TestDefaultToJSONInheritFinal", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestDefaultToJSONInheritFinal) };

JSTestDefaultToJSONInheritFinal::JSTestDefaultToJSONInheritFinal(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestDefaultToJSONInheritFinal>&& impl)
    : JSTestDefaultToJSONInherit(structure, globalObject, WTFMove(impl))
{
}

void JSTestDefaultToJSONInheritFinal::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

    static_assert(!std::is_base_of<ActiveDOMObject, TestDefaultToJSONInheritFinal>::value, "Interface is not marked as [ActiveDOMObject] even though implementation class subclasses ActiveDOMObject.");

}

JSObject* JSTestDefaultToJSONInheritFinal::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestDefaultToJSONInheritFinalPrototype::create(vm, &globalObject, JSTestDefaultToJSONInheritFinalPrototype::createStructure(vm, &globalObject, JSTestDefaultToJSONInherit::prototype(vm, globalObject)));
}

JSObject* JSTestDefaultToJSONInheritFinal::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestDefaultToJSONInheritFinal>(vm, globalObject);
}

JSValue JSTestDefaultToJSONInheritFinal::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestDefaultToJSONInheritFinalDOMConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

template<> inline JSTestDefaultToJSONInheritFinal* IDLAttribute<JSTestDefaultToJSONInheritFinal>::cast(JSGlobalObject& lexicalGlobalObject, EncodedJSValue thisValue)
{
    return jsDynamicCast<JSTestDefaultToJSONInheritFinal*>(JSC::getVM(&lexicalGlobalObject), JSValue::decode(thisValue));
}

template<> inline JSTestDefaultToJSONInheritFinal* IDLOperation<JSTestDefaultToJSONInheritFinal>::cast(JSGlobalObject& lexicalGlobalObject, CallFrame& callFrame)
{
    return jsDynamicCast<JSTestDefaultToJSONInheritFinal*>(JSC::getVM(&lexicalGlobalObject), callFrame.thisValue());
}

JSC_DEFINE_CUSTOM_GETTER(jsTestDefaultToJSONInheritFinalConstructor, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    VM& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicCast<JSTestDefaultToJSONInheritFinalPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(lexicalGlobalObject, throwScope);
    return JSValue::encode(JSTestDefaultToJSONInheritFinal::getConstructor(JSC::getVM(lexicalGlobalObject), prototype->globalObject()));
}

static inline JSValue jsTestDefaultToJSONInheritFinal_finalLongAttributeFooGetter(JSGlobalObject& lexicalGlobalObject, JSTestDefaultToJSONInheritFinal& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLLong>(lexicalGlobalObject, throwScope, impl.finalLongAttributeFoo())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestDefaultToJSONInheritFinal_finalLongAttributeFoo, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    return IDLAttribute<JSTestDefaultToJSONInheritFinal>::get<jsTestDefaultToJSONInheritFinal_finalLongAttributeFooGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "finalLongAttributeFoo");
}

static inline bool setJSTestDefaultToJSONInheritFinal_finalLongAttributeFooSetter(JSGlobalObject& lexicalGlobalObject, JSTestDefaultToJSONInheritFinal& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLLong>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    AttributeSetter::call(lexicalGlobalObject, throwScope, [&] {
        return impl.setFinalLongAttributeFoo(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestDefaultToJSONInheritFinal_finalLongAttributeFoo, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue))
{
    return IDLAttribute<JSTestDefaultToJSONInheritFinal>::set<setJSTestDefaultToJSONInheritFinal_finalLongAttributeFooSetter>(*lexicalGlobalObject, thisValue, encodedValue, "finalLongAttributeFoo");
}

static inline JSValue jsTestDefaultToJSONInheritFinal_finalLongAttributeBarGetter(JSGlobalObject& lexicalGlobalObject, JSTestDefaultToJSONInheritFinal& thisObject)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    RELEASE_AND_RETURN(throwScope, (toJS<IDLLong>(lexicalGlobalObject, throwScope, impl.finalLongAttributeBar())));
}

JSC_DEFINE_CUSTOM_GETTER(jsTestDefaultToJSONInheritFinal_finalLongAttributeBar, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, PropertyName))
{
    return IDLAttribute<JSTestDefaultToJSONInheritFinal>::get<jsTestDefaultToJSONInheritFinal_finalLongAttributeBarGetter, CastedThisErrorBehavior::Assert>(*lexicalGlobalObject, thisValue, "finalLongAttributeBar");
}

static inline bool setJSTestDefaultToJSONInheritFinal_finalLongAttributeBarSetter(JSGlobalObject& lexicalGlobalObject, JSTestDefaultToJSONInheritFinal& thisObject, JSValue value)
{
    auto& vm = JSC::getVM(&lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLLong>(lexicalGlobalObject, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    AttributeSetter::call(lexicalGlobalObject, throwScope, [&] {
        return impl.setFinalLongAttributeBar(WTFMove(nativeValue));
    });
    return true;
}

JSC_DEFINE_CUSTOM_SETTER(setJSTestDefaultToJSONInheritFinal_finalLongAttributeBar, (JSGlobalObject* lexicalGlobalObject, EncodedJSValue thisValue, EncodedJSValue encodedValue))
{
    return IDLAttribute<JSTestDefaultToJSONInheritFinal>::set<setJSTestDefaultToJSONInheritFinal_finalLongAttributeBarSetter>(*lexicalGlobalObject, thisValue, encodedValue, "finalLongAttributeBar");
}

static inline EncodedJSValue jsTestDefaultToJSONInheritFinalPrototypeFunction_toJSONBody(JSGlobalObject* lexicalGlobalObject, CallFrame*, JSTestDefaultToJSONInheritFinal* castedThis)
{
    auto& vm = JSC::getVM(lexicalGlobalObject);
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    auto& impl = castedThis->wrapped();
    auto* result = constructEmptyObject(lexicalGlobalObject, castedThis->globalObject()->objectPrototype());
    if (RuntimeEnabledFeatures::sharedFeatures().testRuntimeEnabledEnabled()) {
        result->putDirect(vm, Identifier::fromString(vm, "longAttribute"), toJS<IDLLong>(*lexicalGlobalObject, throwScope, impl.longAttribute()));
    }
    if (jsCast<JSDOMGlobalObject*>(castedThis->globalObject())->scriptExecutionContext()->settingsValues().testSettingEnabled) {
        result->putDirect(vm, Identifier::fromString(vm, "enabledBySettingsAttribute"), toJS<IDLUnsignedShort>(*lexicalGlobalObject, throwScope, impl.enabledBySettingsAttribute()));
    }
#if ENABLE(TEST_CONDITIONAL)
    result->putDirect(vm, Identifier::fromString(vm, "enabledByConditionalAttribute"), toJS<IDLEnumeration<TestDefaultToJSONEnum>>(*lexicalGlobalObject, throwScope, impl.enabledByConditionalAttribute()));
#endif

    result->putDirect(vm, Identifier::fromString(vm, "firstStringAttribute"), toJS<IDLDOMString>(*lexicalGlobalObject, throwScope, impl.firstStringAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "secondLongAttribute"), toJS<IDLLong>(*lexicalGlobalObject, throwScope, impl.secondLongAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "fourthUnrestrictedDoubleAttribute"), toJS<IDLUnrestrictedDouble>(*lexicalGlobalObject, throwScope, impl.fourthUnrestrictedDoubleAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "fifthLongClampedAttribute"), toJS<IDLClampAdaptor<IDLLong>>(*lexicalGlobalObject, throwScope, impl.fifthLongClampedAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "sixthTypedefAttribute"), toJS<IDLDouble>(*lexicalGlobalObject, throwScope, impl.sixthTypedefAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "seventhDirectlyToJSONableAttribute"), toJS<IDLInterface<TestDefaultToJSONInheritFinal>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.seventhDirectlyToJSONableAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "eighthIndirectlyAttribute"), toJS<IDLInterface<TestDefaultToJSONIndirectInheritance>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.eighthIndirectlyAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "ninthOptionalDirectlyToJSONableAttribute"), toJS<IDLNullable<IDLInterface<TestDefaultToJSONInheritFinal>>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.ninthOptionalDirectlyToJSONableAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "tenthFrozenArrayAttribute"), toJS<IDLFrozenArray<IDLBoolean>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.tenthFrozenArrayAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "eleventhSequenceAttribute"), toJS<IDLSequence<IDLDOMString>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.eleventhSequenceAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "twelfthInterfaceSequenceAttribute"), toJS<IDLSequence<IDLInterface<TestDefaultToJSONInheritFinal>>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.twelfthInterfaceSequenceAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "thirteenthRecordAttribute"), toJS<IDLRecord<IDLDOMString, IDLUnsignedShort>>(*lexicalGlobalObject, *castedThis->globalObject(), throwScope, impl.thirteenthRecordAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "inheritLongAttribute"), toJS<IDLLong>(*lexicalGlobalObject, throwScope, impl.inheritLongAttribute()));
    result->putDirect(vm, Identifier::fromString(vm, "finalLongAttributeFoo"), toJS<IDLLong>(*lexicalGlobalObject, throwScope, impl.finalLongAttributeFoo()));
    result->putDirect(vm, Identifier::fromString(vm, "finalLongAttributeBar"), toJS<IDLLong>(*lexicalGlobalObject, throwScope, impl.finalLongAttributeBar()));
    return JSValue::encode(result);
}

JSC_DEFINE_HOST_FUNCTION(jsTestDefaultToJSONInheritFinalPrototypeFunction_toJSON, (JSGlobalObject* lexicalGlobalObject, CallFrame* callFrame))
{
    return IDLOperation<JSTestDefaultToJSONInheritFinal>::call<jsTestDefaultToJSONInheritFinalPrototypeFunction_toJSONBody>(*lexicalGlobalObject, *callFrame, "toJSON");
}

JSC::IsoSubspace* JSTestDefaultToJSONInheritFinal::subspaceForImpl(JSC::VM& vm)
{
    auto& clientData = *static_cast<JSVMClientData*>(vm.clientData);
    auto& spaces = clientData.subspaces();
    if (auto* space = spaces.m_subspaceForTestDefaultToJSONInheritFinal.get())
        return space;
    static_assert(std::is_base_of_v<JSC::JSDestructibleObject, JSTestDefaultToJSONInheritFinal> || !JSTestDefaultToJSONInheritFinal::needsDestruction);
    if constexpr (std::is_base_of_v<JSC::JSDestructibleObject, JSTestDefaultToJSONInheritFinal>)
        spaces.m_subspaceForTestDefaultToJSONInheritFinal = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.destructibleObjectHeapCellType.get(), JSTestDefaultToJSONInheritFinal);
    else
        spaces.m_subspaceForTestDefaultToJSONInheritFinal = makeUnique<IsoSubspace> ISO_SUBSPACE_INIT(vm.heap, vm.cellHeapCellType.get(), JSTestDefaultToJSONInheritFinal);
    auto* space = spaces.m_subspaceForTestDefaultToJSONInheritFinal.get();
IGNORE_WARNINGS_BEGIN("unreachable-code")
IGNORE_WARNINGS_BEGIN("tautological-compare")
    void (*myVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSTestDefaultToJSONInheritFinal::visitOutputConstraints;
    void (*jsCellVisitOutputConstraint)(JSC::JSCell*, JSC::SlotVisitor&) = JSC::JSCell::visitOutputConstraints;
    if (myVisitOutputConstraint != jsCellVisitOutputConstraint)
        clientData.outputConstraintSpaces().append(space);
IGNORE_WARNINGS_END
IGNORE_WARNINGS_END
    return space;
}

void JSTestDefaultToJSONInheritFinal::analyzeHeap(JSCell* cell, HeapAnalyzer& analyzer)
{
    auto* thisObject = jsCast<JSTestDefaultToJSONInheritFinal*>(cell);
    analyzer.setWrappedObjectForCell(cell, &thisObject->wrapped());
    if (thisObject->scriptExecutionContext())
        analyzer.setLabelForCell(cell, "url " + thisObject->scriptExecutionContext()->url().string());
    Base::analyzeHeap(cell, analyzer);
}


}
