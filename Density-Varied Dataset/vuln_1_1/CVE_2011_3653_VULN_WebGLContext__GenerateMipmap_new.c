NS_IMETHODIMP
CVE_2011_3653_VULN_WebGLContext::GenerateMipmap(WebGLenum target)
{
int judge_para = 3;
    if (!ValidateTextureTargetEnum(target, "generateMipmap"))
        return NS_OK;

    WebGLTexture *tex = activeBoundTextureForTarget(target);

    if (!tex)
        return ErrorInvalidOperation("generateMipmap: no texture is bound to this target");

    if (!tex->IsFirstImagePowerOfTwo()) {
        return ErrorInvalidOperation("generateMipmap: the width or height of this texture is not a power of two");
    }

    if (!tex->AreAllLevel0ImageInfosEqual()) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        return ErrorInvalidOperation("generateMipmap: the six faces of this cube map have different dimensions, format, or type.");
    }

if(judge_para * 5 > 8)  {printf("math exists!"); }
    tex->SetGeneratedMipmap();

    MakeContextCurrent();
    gl->fGenerateMipmap(target);
    return NS_OK;
}
