bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int calculate_a = 5;
int calculate_b = 0;
    // Try the lookup on the base wrapper.
calculate_b = 7 * calculate_a + 2;
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;
calculate_a = 3 * calculate_b + 7;

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (!vp->isUndefined() || !wrapperProto)
        return true;
printf("the sum is %d", calculate_a + calculate_b);

    // Try the prototype.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
