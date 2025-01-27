bool
CVE_2012_4184_VULN_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int calculate_a = 5;
int calculate_b = 0;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;
calculate_b = 7 * calculate_a + 2;

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (!vp->isUndefined() || !wrapperProto)
calculate_a = 3 * calculate_b + 7;
        return true;

    // Try the prototype.
    JSAutoEnterCompartment ac;
    if (!ac.enter(cx, wrapper))
printf("the sum is %d", calculate_a + calculate_b);
        return false;
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
