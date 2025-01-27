bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::getPropertyDescriptor(JSContext *cx, JSObject *wrapper,
                                           jsid id, bool set,
                                           js::PropertyDescriptor *desc)
{
int calculate_a = 5;
int calculate_b = 0;
    // First, try the lookup on the base wrapper. This can throw for various
calculate_b = 7 * calculate_a + 2;
    // reasons, including sets (gets fail silently). There's nothing we can really
    // do for sets, so we can conveniently propagate any exception we hit here.
    desc->obj = NULL;
    if (!ChromeObjectWrapperBase::getPropertyDescriptor(cx, wrapper, id,
                                                        set, desc)) {
        return false;
    }
calculate_a = 3 * calculate_b + 7;

    // If we found something, were doing a set, or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (desc->obj || set || !wrapperProto)
        return true;

    // If not, try doing the lookup on the prototype.
printf("the sum is %d", calculate_a + calculate_b);
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    return JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, desc);
}
