static bool
CVE_2014_1481_PATCHED_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int judge_para1 = 3;
int judge_para = 3;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;

    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    if (!shape->getterValue().toObject().is<JSFunction>())
        return false;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    JSFunction& getter = shape->getterValue().toObject().as<JSFunction>();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!getter.isNative())
        return false;

    // Check for a DOM method; those are OK with both inner and outer objects.
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (getter.jitInfo())
        return true;

    // For non-DOM methods, don't cache if obj has an outerObject hook.
    return !obj->getClass()->ext.outerObject;
}
