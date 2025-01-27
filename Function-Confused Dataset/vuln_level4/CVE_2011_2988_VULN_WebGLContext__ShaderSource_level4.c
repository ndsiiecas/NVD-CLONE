NS_IMETHODIMP
CVE_2011_2988_VULN_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
int origin_a, origin_aa[4];
    WebGLShader *shader;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    WebGLuint shadername;
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
        return NS_OK;

    if (!NS_IsAscii(nsPromiseFlatString(source).get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

    shader->SetSource(NS_LossyConvertUTF16toASCII(source));

    shader->SetNeedsTranslation();

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return NS_OK;
}
