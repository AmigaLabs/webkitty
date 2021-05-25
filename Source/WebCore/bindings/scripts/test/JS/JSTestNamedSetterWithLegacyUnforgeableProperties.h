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

#pragma once

#include "JSDOMWrapper.h"
#include "TestNamedSetterWithLegacyUnforgeableProperties.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class JSTestNamedSetterWithLegacyUnforgeableProperties : public JSDOMWrapper<TestNamedSetterWithLegacyUnforgeableProperties> {
public:
    using Base = JSDOMWrapper<TestNamedSetterWithLegacyUnforgeableProperties>;
    static JSTestNamedSetterWithLegacyUnforgeableProperties* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, Ref<TestNamedSetterWithLegacyUnforgeableProperties>&& impl)
    {
        JSTestNamedSetterWithLegacyUnforgeableProperties* ptr = new (NotNull, JSC::allocateCell<JSTestNamedSetterWithLegacyUnforgeableProperties>(globalObject->vm().heap)) JSTestNamedSetterWithLegacyUnforgeableProperties(structure, *globalObject, WTFMove(impl));
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSDOMGlobalObject&);
    static JSC::JSObject* prototype(JSC::VM&, JSDOMGlobalObject&);
    static TestNamedSetterWithLegacyUnforgeableProperties* toWrapped(JSC::VM&, JSC::JSValue);
    static bool getOwnPropertySlot(JSC::JSObject*, JSC::JSGlobalObject*, JSC::PropertyName, JSC::PropertySlot&);
    static bool getOwnPropertySlotByIndex(JSC::JSObject*, JSC::JSGlobalObject*, unsigned propertyName, JSC::PropertySlot&);
    static void getOwnPropertyNames(JSC::JSObject*, JSC::JSGlobalObject*, JSC::PropertyNameArray&, JSC::DontEnumPropertiesMode);
    static bool put(JSC::JSCell*, JSC::JSGlobalObject*, JSC::PropertyName, JSC::JSValue, JSC::PutPropertySlot&);
    static bool putByIndex(JSC::JSCell*, JSC::JSGlobalObject*, unsigned propertyName, JSC::JSValue, bool shouldThrow);
    static bool defineOwnProperty(JSC::JSObject*, JSC::JSGlobalObject*, JSC::PropertyName, const JSC::PropertyDescriptor&, bool shouldThrow);
    static void destroy(JSC::JSCell*);

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info(), JSC::MayHaveIndexedAccessors);
    }

    static JSC::JSValue getConstructor(JSC::VM&, const JSC::JSGlobalObject*);
    template<typename, JSC::SubspaceAccess mode> static JSC::IsoSubspace* subspaceFor(JSC::VM& vm)
    {
        if constexpr (mode == JSC::SubspaceAccess::Concurrently)
            return nullptr;
        return subspaceForImpl(vm);
    }
    static JSC::IsoSubspace* subspaceForImpl(JSC::VM& vm);
    static void analyzeHeap(JSCell*, JSC::HeapAnalyzer&);
public:
    static constexpr unsigned StructureFlags = Base::StructureFlags | JSC::GetOwnPropertySlotIsImpureForPropertyAbsence | JSC::HasStaticPropertyTable | JSC::InterceptsGetOwnPropertySlotByIndexEvenWhenLengthIsNotZero | JSC::OverridesGetOwnPropertyNames | JSC::OverridesGetOwnPropertySlot | JSC::ProhibitsPropertyCaching;
protected:
    JSTestNamedSetterWithLegacyUnforgeableProperties(JSC::Structure*, JSDOMGlobalObject&, Ref<TestNamedSetterWithLegacyUnforgeableProperties>&&);

    void finishCreation(JSC::VM&);
};

class JSTestNamedSetterWithLegacyUnforgeablePropertiesOwner final : public JSC::WeakHandleOwner {
public:
    bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::AbstractSlotVisitor&, const char**) final;
    void finalize(JSC::Handle<JSC::Unknown>, void* context) final;
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, TestNamedSetterWithLegacyUnforgeableProperties*)
{
    static NeverDestroyed<JSTestNamedSetterWithLegacyUnforgeablePropertiesOwner> owner;
    return &owner.get();
}

inline void* wrapperKey(TestNamedSetterWithLegacyUnforgeableProperties* wrappableObject)
{
    return wrappableObject;
}

JSC::JSValue toJS(JSC::JSGlobalObject*, JSDOMGlobalObject*, TestNamedSetterWithLegacyUnforgeableProperties&);
inline JSC::JSValue toJS(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, TestNamedSetterWithLegacyUnforgeableProperties* impl) { return impl ? toJS(lexicalGlobalObject, globalObject, *impl) : JSC::jsNull(); }
JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject*, JSDOMGlobalObject*, Ref<TestNamedSetterWithLegacyUnforgeableProperties>&&);
inline JSC::JSValue toJSNewlyCreated(JSC::JSGlobalObject* lexicalGlobalObject, JSDOMGlobalObject* globalObject, RefPtr<TestNamedSetterWithLegacyUnforgeableProperties>&& impl) { return impl ? toJSNewlyCreated(lexicalGlobalObject, globalObject, impl.releaseNonNull()) : JSC::jsNull(); }

template<> struct JSDOMWrapperConverterTraits<TestNamedSetterWithLegacyUnforgeableProperties> {
    using WrapperClass = JSTestNamedSetterWithLegacyUnforgeableProperties;
    using ToWrappedReturnType = TestNamedSetterWithLegacyUnforgeableProperties*;
};

} // namespace WebCore
