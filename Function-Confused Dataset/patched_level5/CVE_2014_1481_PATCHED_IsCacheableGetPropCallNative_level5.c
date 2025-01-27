static bool
CVE_2014_1481_PATCHED_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (!shape || !IsCacheableProtoChain(obj, holder))
        return false;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (!shape->hasGetterValue() || !shape->getterValue().isObject())
        return false;

    if (!shape->getterValue().toObject().is<JSFunction>())
        return false;

    JSFunction& getter = shape->getterValue().toObject().as<JSFunction>();
    if (!getter.isNative())
        return false;

    // Check for a DOM method; those are OK with both inner and outer objects.
    if (getter.jitInfo())
        return true;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
    // For non-DOM methods, don't cache if obj has an outerObject hook.
    return !obj->getClass()->ext.outerObject;
}
