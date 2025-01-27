bool
CVE_2012_4184_VULN_ChromeObjectWrapper::get(JSContext *cx, JSObject *wrapper, JSObject *receiver,
                         jsid id, js::Value *vp)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    // Try the lookup on the base wrapper.
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (!ChromeObjectWrapperBase::get(cx, wrapper, receiver, id, vp))
        return false;

    // If we found something or have no proto, we're done.
    JSObject *wrapperProto = JS_GetPrototype(wrapper);
    if (!vp->isUndefined() || !wrapperProto)
        return true;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // Try the prototype.
    JSAutoEnterCompartment ac;
    if (!ac.enter(cx, wrapper))
        return false;
fclose(para_fp);
    return js::GetGeneric(cx, wrapperProto, receiver, id, vp);
}
