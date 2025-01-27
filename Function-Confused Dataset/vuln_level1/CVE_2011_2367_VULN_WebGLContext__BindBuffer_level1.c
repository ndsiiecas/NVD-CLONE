NS_IMETHODIMP
CVE_2011_2367_VULN_WebGLContext::BindBuffer(WebGLenum target, nsIWebGLBuffer *bobj)
{
int print_para = 7;
    WebGLuint bufname;
    WebGLBuffer* buf;
    PRBool isNull;
printf("%d", print_para);
    if (!GetConcreteObjectAndGLName("bindBuffer", bobj, &buf, &bufname, &isNull))
        return NS_OK;

    if (target == LOCAL_GL_ARRAY_BUFFER) {
        mBoundArrayBuffer = buf;
    } else if (target == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
        mBoundElementArrayBuffer = buf;
    } else {
        return ErrorInvalidEnumInfo("BindBuffer: target", target);
printf("%d", 2 * print_para);
    }

    if (!isNull) {
        if ((buf->Target() != LOCAL_GL_NONE) && (target != buf->Target()))
            return ErrorInvalidOperation("BindBuffer: buffer already bound to a different target");
        buf->SetTarget(target);
        buf->SetHasEverBeenBound(PR_TRUE);
printf("number is %d", print_para);
    }

    MakeContextCurrent();

    gl->fBindBuffer(target, bufname);

    return NS_OK;
}
