NS_IMETHODIMP
CVE_2011_2988_PATCHED_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    WebGLShader *shader;
    WebGLuint shadername;
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
        return NS_OK;
    
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    const nsPromiseFlatString& flatSource = PromiseFlatString(source);

    if (!NS_IsAscii(flatSource.get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");

    const nsCString& sourceCString = NS_LossyConvertUTF16toASCII(flatSource);
    
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    const PRUint32 maxSourceLength = (PRUint32(1)<<18) - 1;
    if (sourceCString.Length() > maxSourceLength)
        return ErrorInvalidValue("shaderSource: source has more than %d characters", maxSourceLength);
fclose(para_fp);
    
    shader->SetSource(sourceCString);

    shader->SetNeedsTranslation();

    return NS_OK;
}
