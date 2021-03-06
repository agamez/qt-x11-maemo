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
#include "JSHTMLOptionElement.h"

#include "HTMLFormElement.h"
#include "HTMLOptionElement.h"
#include "JSHTMLFormElement.h"
#include "KURL.h"
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLOptionElement);

/* Hash table */

static const HashTableValue JSHTMLOptionElementTableValues[10] =
{
    { "form", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementForm), (intptr_t)0 },
    { "defaultSelected", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementDefaultSelected), (intptr_t)setJSHTMLOptionElementDefaultSelected },
    { "text", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementText), (intptr_t)setJSHTMLOptionElementText },
    { "index", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementIndex), (intptr_t)0 },
    { "disabled", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementDisabled), (intptr_t)setJSHTMLOptionElementDisabled },
    { "label", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementLabel), (intptr_t)setJSHTMLOptionElementLabel },
    { "selected", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementSelected), (intptr_t)setJSHTMLOptionElementSelected },
    { "value", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementValue), (intptr_t)setJSHTMLOptionElementValue },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionElementConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOptionElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSHTMLOptionElementTableValues, 0 };
#else
    { 34, 31, JSHTMLOptionElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLOptionElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOptionElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLOptionElementConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLOptionElementConstructorTableValues, 0 };
#endif

class JSHTMLOptionElementConstructor : public DOMConstructorObject {
public:
    JSHTMLOptionElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLOptionElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLOptionElementPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSHTMLOptionElementConstructor::s_info = { "HTMLOptionElementConstructor", 0, &JSHTMLOptionElementConstructorTable, 0 };

bool JSHTMLOptionElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOptionElementConstructor, DOMObject>(exec, &JSHTMLOptionElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLOptionElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOptionElementConstructor, DOMObject>(exec, &JSHTMLOptionElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLOptionElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLOptionElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLOptionElementPrototypeTableValues, 0 };
#else
    { 1, 0, JSHTMLOptionElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLOptionElementPrototype::s_info = { "HTMLOptionElementPrototype", 0, &JSHTMLOptionElementPrototypeTable, 0 };

JSObject* JSHTMLOptionElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLOptionElement>(exec, globalObject);
}

const ClassInfo JSHTMLOptionElement::s_info = { "HTMLOptionElement", &JSHTMLElement::s_info, &JSHTMLOptionElementTable, 0 };

JSHTMLOptionElement::JSHTMLOptionElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLOptionElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLOptionElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLOptionElementPrototype(JSHTMLOptionElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLOptionElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOptionElement, Base>(exec, &JSHTMLOptionElementTable, this, propertyName, slot);
}

bool JSHTMLOptionElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOptionElement, Base>(exec, &JSHTMLOptionElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLOptionElementForm(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->form()));
    return result;
}

JSValue jsHTMLOptionElementDefaultSelected(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsBoolean(imp->defaultSelected());
    return result;
}

JSValue jsHTMLOptionElementText(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->text());
    return result;
}

JSValue jsHTMLOptionElementIndex(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->index());
    return result;
}

JSValue jsHTMLOptionElementDisabled(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsBoolean(imp->disabled());
    return result;
}

JSValue jsHTMLOptionElementLabel(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->label());
    return result;
}

JSValue jsHTMLOptionElementSelected(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsBoolean(imp->selected());
    return result;
}

JSValue jsHTMLOptionElementValue(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* castedThis = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->value());
    return result;
}

JSValue jsHTMLOptionElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionElement* domObject = static_cast<JSHTMLOptionElement*>(asObject(slotBase));
    return JSHTMLOptionElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLOptionElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLOptionElement, Base>(exec, propertyName, value, &JSHTMLOptionElementTable, this, slot);
}

void setJSHTMLOptionElementDefaultSelected(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionElement* castedThisObj = static_cast<JSHTMLOptionElement*>(thisObject);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThisObj->impl());
    imp->setDefaultSelected(value.toBoolean(exec));
}

void setJSHTMLOptionElementText(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionElement* castedThisObj = static_cast<JSHTMLOptionElement*>(thisObject);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    imp->setText(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

void setJSHTMLOptionElementDisabled(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionElement* castedThisObj = static_cast<JSHTMLOptionElement*>(thisObject);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThisObj->impl());
    imp->setDisabled(value.toBoolean(exec));
}

void setJSHTMLOptionElementLabel(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionElement* castedThisObj = static_cast<JSHTMLOptionElement*>(thisObject);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThisObj->impl());
    imp->setLabel(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLOptionElementSelected(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionElement* castedThisObj = static_cast<JSHTMLOptionElement*>(thisObject);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThisObj->impl());
    imp->setSelected(value.toBoolean(exec));
}

void setJSHTMLOptionElementValue(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionElement* castedThisObj = static_cast<JSHTMLOptionElement*>(thisObject);
    HTMLOptionElement* imp = static_cast<HTMLOptionElement*>(castedThisObj->impl());
    imp->setValue(valueToStringWithNullCheck(exec, value));
}

JSValue JSHTMLOptionElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLOptionElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

HTMLOptionElement* toHTMLOptionElement(JSC::JSValue value)
{
    return value.inherits(&JSHTMLOptionElement::s_info) ? static_cast<JSHTMLOptionElement*>(asObject(value))->impl() : 0;
}

}
