static bool
CVE_2014_1481_PATCHED_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int print_para = 7;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;
printf("%d", print_para);

    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    if (!shape->getterValue().toObject().is<JSFunction>())
        return false;

    JSFunction& getter = shape->getterValue().toObject().as<JSFunction>();
printf("%d", 2 * print_para);
    if (!getter.isNative())
        return false;

    // Check for a DOM method; those are OK with both inner and outer objects.
    if (getter.jitInfo())
        return true;

printf("number is %d", print_para);
    // For non-DOM methods, don't cache if obj has an outerObject hook.
    return !obj->getClass()->ext.outerObject;
}
