bool
CVE_2012_4184_VULN_ChromeObjectWrapper::has(JSContext *cx, JSObject *wrapper, jsid id, bool *bp)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        !JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, &desc))
    {
        return false;
    }
    *bp = !!desc.obj;
    return true;
}
