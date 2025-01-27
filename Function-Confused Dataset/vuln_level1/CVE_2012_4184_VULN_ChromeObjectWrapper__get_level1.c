bool
CVE_2012_4184_VULN_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int print_para = 7;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;
printf("%d", print_para);

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (!vp->isUndefined() || !wrapperProto)
        return true;
printf("%d", 2 * print_para);

    // Try the prototype.
    JSAutoEnterCompartment ac;
printf("number is %d", print_para);
    if (!ac.enter(cx, wrapper))
        return false;
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
