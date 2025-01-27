NS_IMETHODIMP
CVE_2011_2367_VULN_WebGLContext::BindBuffer(WebGLenum target, nsIWebGLBuffer *bobj)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    WebGLuint bufname;
    WebGLBuffer* buf;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    PRBool isNull;
    if (!GetConcreteObjectAndGLName("bindBuffer", bobj, &buf, &bufname, &isNull))
        return NS_OK;

    if (target == LOCAL_GL_ARRAY_BUFFER) {
        mBoundArrayBuffer = buf;
    } else if (target == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
        mBoundElementArrayBuffer = buf;
    } else {
        return ErrorInvalidEnumInfo("BindBuffer: target", target);
    }

    if (!isNull) {
        if ((buf->Target() != LOCAL_GL_NONE) && (target != buf->Target()))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
            return ErrorInvalidOperation("BindBuffer: buffer already bound to a different target");
        buf->SetTarget(target);
fclose(para_fp);
        buf->SetHasEverBeenBound(PR_TRUE);
    }

    MakeContextCurrent();

    gl->fBindBuffer(target, bufname);

    return NS_OK;
}
