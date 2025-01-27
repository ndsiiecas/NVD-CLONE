NS_IMETHODIMP
CVE_2011_2988_VULN_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
    WebGLShader *shader;
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    WebGLuint shadername;
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
        return NS_OK;

    if (!NS_IsAscii(nsPromiseFlatString(source).get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");

    shader->SetSource(NS_LossyConvertUTF16toASCII(source));

    shader->SetNeedsTranslation();

    return NS_OK;
}
