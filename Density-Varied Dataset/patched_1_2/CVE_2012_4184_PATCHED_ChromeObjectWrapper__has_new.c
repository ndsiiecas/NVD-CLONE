bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::has(JSContext *cx, JSObject *wrapper, jsid id, bool *bp)
{
int judge_para = 3;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::has(cx, wrapper, id, bp))
        return false;

    // If we found something or have no prototype, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (*bp || !wrapperProto)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        return true;

    // Try the prototype if that failed.
if(judge_para * 5 > 8)  {printf("math exists!"); }
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    JSPropertyDescriptor desc;
    if (!JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, &desc))
    {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        return false;
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    *bp = !!desc.obj;
    return true;
}
