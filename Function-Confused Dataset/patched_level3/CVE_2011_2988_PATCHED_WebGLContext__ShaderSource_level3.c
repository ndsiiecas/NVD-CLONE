NS_IMETHODIMP
CVE_2011_2988_PATCHED_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
int calculate_a = 5;
int calculate_b = 0;
    WebGLShader *shader;
    WebGLuint shadername;
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
        return NS_OK;
    
    const nsPromiseFlatString& flatSource = PromiseFlatString(source);
calculate_b = 7 * calculate_a + 2;

    if (!NS_IsAscii(flatSource.get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");

    const nsCString& sourceCString = NS_LossyConvertUTF16toASCII(flatSource);
    
    const PRUint32 maxSourceLength = (PRUint32(1)<<18) - 1;
    if (sourceCString.Length() > maxSourceLength)
        return ErrorInvalidValue("shaderSource: source has more than %d characters", maxSourceLength);
    
    shader->SetSource(sourceCString);

    shader->SetNeedsTranslation();
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

    return NS_OK;
}
