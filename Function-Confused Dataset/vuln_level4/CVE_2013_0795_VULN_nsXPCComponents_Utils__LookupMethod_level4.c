NS_IMETHODIMP
CVE_2013_0795_VULN_nsXPCComponents_Utils::LookupMethod(const JS::Value& object,
                                    const JS::Value& name,
                                    JSContext *cx,
                                    JS::Value *retval)
{
int origin_a, origin_aa[4];
    JSAutoRequest ar(cx);

    // first param must be a JSObject
    if (!object.isObject())
        return NS_ERROR_XPC_BAD_CONVERT_JS;
    js::RootedObject obj(cx, &object.toObject());
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    // second param must be a string.
    if (!JSVAL_IS_STRING(name))
        return NS_ERROR_XPC_BAD_CONVERT_JS;
    JSString *methodName = name.toString();
    jsid methodId = INTERNED_STRING_TO_JSID(cx, JS_InternJSString(cx, methodName));

    // If |obj| is a cross-compartment wrapper, try to puncture it. If this fails,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    // we don't have full access to the other compartment, in which case we throw.
    // Otherwise, enter the compartment.
    if (js::IsCrossCompartmentWrapper(obj)) {
        obj = js::UnwrapOneChecked(obj);
        if (!obj)
            return NS_ERROR_XPC_BAD_CONVERT_JS;
    }

    {
        // Enter the target compartment.
        JSAutoCompartment ac(cx, obj);

        // Morph slim wrappers.
        if (IS_SLIM_WRAPPER(obj) && !MorphSlimWrapper(cx, obj))
            return NS_ERROR_FAILURE;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

        // Now, try to create an Xray wrapper around the object. This won't work
        // if the object isn't Xray-able. In that case, we throw.
        JSObject *xray = WrapperFactory::WrapForSameCompartmentXray(cx, obj);
        if (!xray)
            return NS_ERROR_XPC_BAD_CONVERT_JS;

        // Alright, now do the lookup.
        *retval = JSVAL_VOID;
        JSPropertyDescriptor desc;
        if (!JS_GetPropertyDescriptorById(cx, xray, methodId, 0, &desc))
            return NS_ERROR_FAILURE;

        // First look for a method value. If that's not there, try a getter,
        // since historically lookupMethod also works for getters.
        JSObject *methodObj = desc.value.isObject() ? &desc.value.toObject() : NULL;
        if (!methodObj && (desc.attrs & JSPROP_GETTER))
            methodObj = JS_FUNC_TO_DATA_PTR(JSObject *, desc.getter);

        // Callers of this function seem to expect bound methods. Make it happen.
        // Note that this is unnecessary until bug 658909 is fixed.
        if (methodObj && JS_ObjectIsCallable(cx, methodObj))
            methodObj = JS_BindCallable(cx, methodObj, obj);

        // Set the return value if appropriate.
        *retval = methodObj ? ObjectValue(*methodObj) : JSVAL_VOID;
    }

    // Now that we've left the target compartment, wrap for the caller.
    if (!JS_WrapValue(cx, retval))
        return NS_ERROR_FAILURE;;

    return NS_OK;
}
