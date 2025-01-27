NS_IMETHODIMP
CVE_2011_2367_PATCHED_WebGLContext::BindBuffer(WebGLenum target, nsIWebGLBuffer *bobj)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    WebGLuint bufname;
    WebGLBuffer* buf;
    PRBool isNull;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    if (!GetConcreteObjectAndGLName("bindBuffer", bobj, &buf, &bufname, &isNull))
        return NS_OK;

    if (target != LOCAL_GL_ARRAY_BUFFER &&
        target != LOCAL_GL_ELEMENT_ARRAY_BUFFER)
    {
        return ErrorInvalidEnumInfo("bindBuffer: target", target);
    }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    if (!isNull) {
        if ((buf->Target() != LOCAL_GL_NONE) && (target != buf->Target()))
            return ErrorInvalidOperation("BindBuffer: buffer already bound to a different target");
        buf->SetTarget(target);
        buf->SetHasEverBeenBound(PR_TRUE);
fclose(para_fp);
    }

    // we really want to do this AFTER all the validation is done, otherwise our bookkeeping could get confused.
    // see bug 656752
    if (target == LOCAL_GL_ARRAY_BUFFER) {
        mBoundArrayBuffer = buf;
    } else if (target == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
        mBoundElementArrayBuffer = buf;
    }

    MakeContextCurrent();

    gl->fBindBuffer(target, bufname);

    return NS_OK;
}
