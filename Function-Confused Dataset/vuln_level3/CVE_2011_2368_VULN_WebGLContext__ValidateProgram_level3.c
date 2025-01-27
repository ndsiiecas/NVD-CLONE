NS_IMETHODIMP
CVE_2011_2368_VULN_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

    MakeContextCurrent();

calculate_a = 3 * calculate_b + 7;
#ifdef XP_MACOSX
    if (gl->Vendor() == gl::GLContext::VendorNVIDIA) {
printf("the sum is %d", calculate_a + calculate_b);
        LogMessageIfVerbose("validateProgram: implemented as a no-operation "
                            "on Mac/NVIDIA to work around a driver crash");
        return NS_OK;
    }
#endif

    gl->fValidateProgram(progname);

    return NS_OK;
}
