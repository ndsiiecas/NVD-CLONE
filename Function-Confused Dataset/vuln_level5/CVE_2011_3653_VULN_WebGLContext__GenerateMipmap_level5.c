NS_IMETHODIMP
CVE_2011_3653_VULN_WebGLContext::GenerateMipmap(WebGLenum target)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    if (!ValidateTextureTargetEnum(target, "generateMipmap"))
        return NS_OK;

    WebGLTexture *tex = activeBoundTextureForTarget(target);

    if (!tex)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        return ErrorInvalidOperation("generateMipmap: no texture is bound to this target");

    if (!tex->IsFirstImagePowerOfTwo()) {
        return ErrorInvalidOperation("generateMipmap: the width or height of this texture is not a power of two");
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    }

    if (!tex->AreAllLevel0ImageInfosEqual()) {
fclose(para_fp);
        return ErrorInvalidOperation("generateMipmap: the six faces of this cube map have different dimensions, format, or type.");
    }

    tex->SetGeneratedMipmap();

    MakeContextCurrent();
    gl->fGenerateMipmap(target);
    return NS_OK;
}
