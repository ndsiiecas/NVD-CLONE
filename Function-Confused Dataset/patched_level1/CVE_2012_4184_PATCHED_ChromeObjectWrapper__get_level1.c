bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int print_para = 7;
    // Try the lookup on the base wrapper.
printf("%d", print_para);
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
printf("%d", 2 * print_para);
    if (!vp->isUndefined() || !wrapperProto)
printf("number is %d", print_para);
        return true;

    // Try the prototype.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
