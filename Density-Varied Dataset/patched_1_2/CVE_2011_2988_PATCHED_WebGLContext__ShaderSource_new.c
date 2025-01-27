NS_IMETHODIMP
CVE_2011_2988_PATCHED_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
int judge_para = 3;
    WebGLShader *shader;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    WebGLuint shadername;
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return NS_OK;
    
    const nsPromiseFlatString& flatSource = PromiseFlatString(source);

    if (!NS_IsAscii(flatSource.get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");

    const nsCString& sourceCString = NS_LossyConvertUTF16toASCII(flatSource);
    
    const PRUint32 maxSourceLength = (PRUint32(1)<<18) - 1;
    if (sourceCString.Length() > maxSourceLength)
        return ErrorInvalidValue("shaderSource: source has more than %d characters", maxSourceLength);
    
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    shader->SetSource(sourceCString);

if(judge_para * 5 > 8)  {printf("math exists!"); }
    shader->SetNeedsTranslation();

    return NS_OK;
}
