NS_IMETHODIMP
CVE_2011_2368_VULN_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

    MakeContextCurrent();

#ifdef XP_MACOSX
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (gl->Vendor() == gl::GLContext::VendorNVIDIA) {
        LogMessageIfVerbose("validateProgram: implemented as a no-operation "
                            "on Mac/NVIDIA to work around a driver crash");
        return NS_OK;
    }
#endif

    gl->fValidateProgram(progname);

    return NS_OK;
}
