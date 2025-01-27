NS_IMETHODIMP
CVE_2011_2988_VULN_WebGLContext::ShaderSource(nsIWebGLShader *sobj, const nsAString& source)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
    WebGLShader *shader;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    WebGLuint shadername;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (!GetConcreteObjectAndGLName("shaderSource: shader", sobj, &shader, &shadername))
        return NS_OK;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (!NS_IsAscii(nsPromiseFlatString(source).get()))
        return ErrorInvalidValue("shaderSource: non-ascii characters found in source");

    shader->SetSource(NS_LossyConvertUTF16toASCII(source));
if(judge_para * 5 > 8)  {printf("math exists!"); }

    shader->SetNeedsTranslation();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    return NS_OK;
}
