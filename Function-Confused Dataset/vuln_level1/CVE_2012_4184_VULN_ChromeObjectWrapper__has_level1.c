bool
CVE_2012_4184_VULN_ChromeObjectWrapper::has(JSContext *cx, JSObject *wrapper, jsid id, bool *bp)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::has(cx, wrapper, id, bp))
        return false;

    // If we found something or have no prototype, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (*bp || !wrapperProto)
        return true;

    // Try the prototype if that failed.
    JSAutoEnterCompartment ac;
    JSPropertyDescriptor desc;
    if (!ac.enter(cx, wrapper) ||
        !JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, &desc))
printf("number is %d", print_para);
    {
        return false;
    }
    *bp = !!desc.obj;
    return true;
}
