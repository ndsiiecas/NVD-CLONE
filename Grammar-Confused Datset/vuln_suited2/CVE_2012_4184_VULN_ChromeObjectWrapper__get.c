bool
CVE_2012_4184_VULN_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        return false;

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (!vp->isUndefined() || !wrapperProto)
        return true;

    // Try the prototype.
    JSAutoEnterCompartment ac;
    if (!ac.enter(cx, wrapper))
        return false;
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
