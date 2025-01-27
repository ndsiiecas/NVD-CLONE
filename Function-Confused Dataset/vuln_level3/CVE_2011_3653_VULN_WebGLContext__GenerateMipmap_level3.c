NS_IMETHODIMP
CVE_2011_3653_VULN_WebGLContext::GenerateMipmap(WebGLenum target)
{
int calculate_a = 5;
int calculate_b = 0;
    if (!ValidateTextureTargetEnum(target, "generateMipmap"))
        return NS_OK;

    WebGLTexture *tex = activeBoundTextureForTarget(target);

    if (!tex)
        return ErrorInvalidOperation("generateMipmap: no texture is bound to this target");
calculate_b = 7 * calculate_a + 2;

    if (!tex->IsFirstImagePowerOfTwo()) {
        return ErrorInvalidOperation("generateMipmap: the width or height of this texture is not a power of two");
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    }

    if (!tex->AreAllLevel0ImageInfosEqual()) {
        return ErrorInvalidOperation("generateMipmap: the six faces of this cube map have different dimensions, format, or type.");
    }

    tex->SetGeneratedMipmap();

    MakeContextCurrent();
    gl->fGenerateMipmap(target);
    return NS_OK;
}
