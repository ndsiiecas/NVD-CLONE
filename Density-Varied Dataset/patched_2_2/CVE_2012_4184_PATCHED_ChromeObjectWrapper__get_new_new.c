bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int judge_para1 = 3;
int judge_para = 3;
    // Try the lookup on the base wrapper.
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;

    // If we found something or have no proto, we're done.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!vp->isUndefined() || !wrapperProto)
        return true;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    // Try the prototype.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
