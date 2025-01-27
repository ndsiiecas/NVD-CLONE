static bool
CVE_2014_1481_PATCHED_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    if (!shape->getterValue().toObject().is<JSFunction>())
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        return false;

    JSFunction& getter = shape->getterValue().toObject().as<JSFunction>();
    if (!getter.isNative())
        return false;

    // Check for a DOM method; those are OK with both inner and outer objects.
    if (getter.jitInfo())
        return true;

    // For non-DOM methods, don't cache if obj has an outerObject hook.
    return !obj->getClass()->ext.outerObject;
}
