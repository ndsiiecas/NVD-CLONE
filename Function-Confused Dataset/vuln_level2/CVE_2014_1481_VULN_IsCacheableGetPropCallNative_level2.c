static bool
CVE_2014_1481_VULN_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int judge_para = 3;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;

    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return false;

    return shape->getterValue().toObject().is<JSFunction>() &&
           shape->getterValue().toObject().as<JSFunction>().isNative();
}
