NS_IMETHODIMP
CVE_2011_2367_PATCHED_WebGLContext::BindBuffer(WebGLenum target, nsIWebGLBuffer *bobj)
{
int judge_para1 = 3;
int judge_para = 3;
    WebGLuint bufname;
    WebGLBuffer* buf;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    PRBool isNull;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!GetConcreteObjectAndGLName("bindBuffer", bobj, &buf, &bufname, &isNull))
        return NS_OK;

if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (target != LOCAL_GL_ARRAY_BUFFER &&
        target != LOCAL_GL_ELEMENT_ARRAY_BUFFER)
    {
        return ErrorInvalidEnumInfo("bindBuffer: target", target);
    }

    if (!isNull) {
        if ((buf->Target() != LOCAL_GL_NONE) && (target != buf->Target()))
            return ErrorInvalidOperation("BindBuffer: buffer already bound to a different target");
        buf->SetTarget(target);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        buf->SetHasEverBeenBound(PR_TRUE);
    }

    // we really want to do this AFTER all the validation is done, otherwise our bookkeeping could get confused.
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    // see bug 656752
    if (target == LOCAL_GL_ARRAY_BUFFER) {
        mBoundArrayBuffer = buf;
    } else if (target == LOCAL_GL_ELEMENT_ARRAY_BUFFER) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        mBoundElementArrayBuffer = buf;
    }

    MakeContextCurrent();

    gl->fBindBuffer(target, bufname);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    return NS_OK;
}
