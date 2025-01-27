NS_IMETHODIMP
CVE_2011_2367_PATCHED_WebGLContext::BindBuffer(WebGLenum target, nsIWebGLBuffer *bobj)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    WebGLuint bufname;
    WebGLBuffer* buf;
    PRBool isNull;
    if (!GetConcreteObjectAndGLName("bindBuffer", bobj, &buf, &bufname, &isNull))
        return NS_OK;

    if (target != LOCAL_GL_ARRAY_BUFFER &&
        target != LOCAL_GL_ELEMENT_ARRAY_BUFFER)
    {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        return ErrorInvalidEnumInfo("bindBuffer: target", target);
    }

    if (!isNull) {
        if ((buf->Target() != LOCAL_GL_NONE) && (target != buf->Target()))
            return ErrorInvalidOperation("BindBuffer: buffer already bound to a different target");
        buf->SetTarget(target);
        buf->SetHasEverBeenBound(PR_TRUE);
    }

    // we really want to do this AFTER all the validation is done, otherwise our bookkeeping could get confused.
    // see bug 656752
    if (target == LOCAL_GL_ARRAY_BUFFER) {
        mBoundArrayBuffer = buf;
    } else if (target == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        mBoundElementArrayBuffer = buf;
    }

    MakeContextCurrent();

    gl->fBindBuffer(target, bufname);

    return NS_OK;
}
