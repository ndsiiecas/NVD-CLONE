bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
int origin_a, origin_aa[4];
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;

    // If we found something or have no proto, we're done.
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (!vp->isUndefined() || !wrapperProto)
        return true;

    // Try the prototype.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
