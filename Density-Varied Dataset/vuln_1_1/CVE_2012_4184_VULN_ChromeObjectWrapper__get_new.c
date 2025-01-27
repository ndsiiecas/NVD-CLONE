bool
CVE_2012_4184_VULN_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int judge_para = 3;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        return false;

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (!vp->isUndefined() || !wrapperProto)
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return true;

    // Try the prototype.
    JSAutoEnterCompartment ac;
    if (!ac.enter(cx, wrapper))
        return false;
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
