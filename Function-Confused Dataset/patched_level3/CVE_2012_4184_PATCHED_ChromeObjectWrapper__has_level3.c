bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::has(JSContext *cx, JSObject *wrapper, jsid id, bool *bp)
{
int calculate_a = 5;
int calculate_b = 0;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::has(cx, wrapper, id, bp))
        return false;

    // If we found something or have no prototype, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (*bp || !wrapperProto)
        return true;
calculate_b = 7 * calculate_a + 2;

    // Try the prototype if that failed.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    JSPropertyDescriptor desc;
calculate_a = 3 * calculate_b + 7;
    if (!JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, &desc))
    {
        return false;
    }
printf("the sum is %d", calculate_a + calculate_b);
    *bp = !!desc.obj;
    return true;
}
