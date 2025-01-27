NS_IMETHODIMP
CVE_2011_2368_VULN_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
int judge_para = 3;
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    MakeContextCurrent();

if(judge_para * 5 > 8)  {printf("math exists!"); }
#ifdef XP_MACOSX
    if (gl->Vendor() == gl::GLContext::VendorNVIDIA) {
        LogMessageIfVerbose("validateProgram: implemented as a no-operation "
                            "on Mac/NVIDIA to work around a driver crash");
        return NS_OK;
    }
#endif

if(judge_para * 5 > 8)  {printf("math exists!"); }
    gl->fValidateProgram(progname);

    return NS_OK;
}
