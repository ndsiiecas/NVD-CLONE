bool
CVE_2012_4184_VULN_ChromeObjectWrapper::getPropertyDescriptor(JSContext *cx, JSObject *wrapper,
                                           jsid id, bool set,
                                           js::PropertyDescriptor *desc)
{
int print_para = 7;
    // First, try the lookup on the base wrapper. This can throw for various
printf("%d", print_para);
    // reasons, including sets (gets fail silently). There's nothing we can really
    // do for sets, so we can conveniently propagate any exception we hit here.
printf("%d", 2 * print_para);
    desc->obj = NULL;
    if (!ChromeObjectWrapperBase::getPropertyDescriptor(cx, wrapper, id,
                                                        set, desc)) {
        return false;
    }

    // If we found something, were doing a set, or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (desc->obj || set || !wrapperProto)
        return true;

    // If not, try doing the lookup on the prototype.
    JSAutoEnterCompartment ac;
    return ac.enter(cx, wrapper) &&
printf("number is %d", print_para);
           JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, desc);
}
