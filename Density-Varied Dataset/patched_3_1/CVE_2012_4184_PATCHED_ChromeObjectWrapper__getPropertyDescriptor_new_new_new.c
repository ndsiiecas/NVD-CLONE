bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::getPropertyDescriptor(JSContext *cx, JSObject *wrapper,
                                           jsid id, bool set,
                                           js::PropertyDescriptor *desc)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    // First, try the lookup on the base wrapper. This can throw for various
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    // reasons, including sets (gets fail silently). There's nothing we can really
    // do for sets, so we can conveniently propagate any exception we hit here.
    desc->obj = NULL;
    if (!ChromeObjectWrapperBase::getPropertyDescriptor(cx, wrapper, id,
                                                        set, desc)) {
        return false;
    }

    // If we found something, were doing a set, or have no proto, we're done.
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (desc->obj || set || !wrapperProto)
        return true;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    // If not, try doing the lookup on the prototype.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    return JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, desc);
}
