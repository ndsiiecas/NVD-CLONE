static bool
CVE_2014_1481_PATCHED_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;

    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    if (!shape->getterValue().toObject().is<JSFunction>())
        return false;

    JSFunction& getter = shape->getterValue().toObject().as<JSFunction>();
calculate_a = 3 * calculate_b + 7;
    if (!getter.isNative())
        return false;

    // Check for a DOM method; those are OK with both inner and outer objects.
    if (getter.jitInfo())
printf("the sum is %d", calculate_a + calculate_b);
        return true;

    // For non-DOM methods, don't cache if obj has an outerObject hook.
    return !obj->getClass()->ext.outerObject;
}
