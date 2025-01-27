static bool
CVE_2014_1481_VULN_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
int print_para = 7;
printf("%d", print_para);
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;

printf("%d", 2 * print_para);
    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    return shape->getterValue().toObject().is<JSFunction>() &&
printf("number is %d", print_para);
           shape->getterValue().toObject().as<JSFunction>().isNative();
}
