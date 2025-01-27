static bool
CVE_2014_1481_VULN_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
    if (!shape || !IsCacheableProtoChain(obj, holder))
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        return false;

    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    return shape->getterValue().toObject().is<JSFunction>() &&
           shape->getterValue().toObject().as<JSFunction>().isNative();
}
