NS_IMETHODIMP
CVE_2011_2988_PATCHED_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
int origin_a, origin_aa[4];
    WebGLShader *shader;
    WebGLuint shadername;
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        return NS_OK;
    
    const nsPromiseFlatString& flatSource = PromiseFlatString(source);

    if (!NS_IsAscii(flatSource.get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    const nsCString& sourceCString = NS_LossyConvertUTF16toASCII(flatSource);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    
    const PRUint32 maxSourceLength = (PRUint32(1)<<18) - 1;
    if (sourceCString.Length() > maxSourceLength)
        return ErrorInvalidValue("shaderSource: source has more than %d characters", maxSourceLength);
    
    shader->SetSource(sourceCString);

    shader->SetNeedsTranslation();

    return NS_OK;
}
