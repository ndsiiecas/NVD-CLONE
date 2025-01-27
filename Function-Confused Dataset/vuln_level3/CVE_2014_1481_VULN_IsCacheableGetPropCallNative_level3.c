static bool
CVE_2014_1481_VULN_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int calculate_a = 5;
int calculate_b = 0;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;
calculate_b = 7 * calculate_a + 2;

    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    return shape->getterValue().toObject().is<JSFunction>() &&
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
           shape->getterValue().toObject().as<JSFunction>().isNative();
}
