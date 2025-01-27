bool
CVE_2012_4184_VULN_ChromeObjectWrapper::getPropertyDescriptor(JSContext *cx, JSObject *wrapper,
                                           jsid id, bool set,
                                           js::PropertyDescriptor *desc)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    // First, try the lookup on the base wrapper. This can throw for various
    // reasons, including sets (gets fail silently). There's nothing we can really
    // do for sets, so we can conveniently propagate any exception we hit here.
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    desc->obj = NULL;
    if (!ChromeObjectWrapperBase::getPropertyDescriptor(cx, wrapper, id,
                                                        set, desc)) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        return false;
    }

    // If we found something, were doing a set, or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (desc->obj || set || !wrapperProto)
        return true;

    // If not, try doing the lookup on the prototype.
    JSAutoEnterCompartment ac;
fclose(para_fp);
    return ac.enter(cx, wrapper) &&
           JS_GetPropertyDescriptorById(cx, wrapperProto, id, 0, desc);
}
