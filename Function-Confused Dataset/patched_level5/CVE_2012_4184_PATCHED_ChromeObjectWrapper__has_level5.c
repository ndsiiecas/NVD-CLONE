bool
CVE_2012_4184_PATCHED_ChromeObjectWrapper::has(JSContext *cx, JSObject *wrapper, jsid id, bool *bp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    // Try the lookup on the base wrapper.
    if (!ChromeObjectWrapperBase::has(cx, wrapper, id, bp))
        return false;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    // If we found something or have no prototype, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (*bp || !wrapperProto)
        return true;

    // Try the prototype if that failed.
    JS_ASSERT(js::IsObjectInContextCompartment(wrapper, cx));
    JSPropertyDescriptor desc;
    if (!JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, &desc))
    {
fclose(para_fp);
        return false;
    }
    *bp = !!desc.obj;
    return true;
}
