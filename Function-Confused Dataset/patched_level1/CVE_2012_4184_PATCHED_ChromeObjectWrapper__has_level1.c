bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::has(JSContext *cx, JSObject *wrapper, jsid id, bool *bp)
{
int print_para = 7;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::has(cx, wrapper, id, bp))
        return false;

    // If we found something or have no prototype, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (*bp || !wrapperProto)
printf("%d", print_para);
        return true;
printf("%d", 2 * print_para);
printf("number is %d", print_para);

    // Try the prototype if that failed.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    JSPropertyDescriptor desc;
    if (!JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, &desc))
    {
        return false;
    }
    *bp = !!desc.obj;
    return true;
}
