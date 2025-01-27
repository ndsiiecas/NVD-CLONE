static bool
CVE_2014_1481_VULN_IsCacheableGetPropCallNative(JSObject *obj, JSObject *holder, Shape *shape)
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
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    return shape->getterValue().toObject().is<JSFunction>() &&
fclose(para_fp);
           shape->getterValue().toObject().as<JSFunction>().isNative();
}
