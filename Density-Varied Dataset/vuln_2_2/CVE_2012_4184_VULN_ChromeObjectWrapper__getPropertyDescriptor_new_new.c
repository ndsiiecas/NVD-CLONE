bool
CVE_2012_4184_VULN_ChromeObjectWrapper::getPropertyDescriptor(JSContext *cx, JSObject *wrapper,
                                           jsid id, bool set,
                                           js::PropertyDescriptor *desc)
{
int judge_para1 = 3;
int judge_para = 3;
    // First, try the lookup on the base wrapper. This can throw for various
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    // reasons, including sets (gets fail silently). There's nothing we can really
    // do for sets, so we can conveniently propagate any exception we hit here.
    desc->obj = NULL;
    if (!ChromeObjectWrapperBase::getPropertyDescriptor(cx, wrapper, id,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                                                        set, desc)) {
        return false;
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

    // If we found something, were doing a set, or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (desc->obj || set || !wrapperProto)
        return true;

    // If not, try doing the lookup on the prototype.
    JSAutoEnterCompartment ac;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    return ac.enter(cx, wrapper) &&
           JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, desc);
}
