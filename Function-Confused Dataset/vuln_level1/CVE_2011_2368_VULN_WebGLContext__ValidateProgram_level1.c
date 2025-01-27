NS_IMETHODIMP
CVE_2011_2368_VULN_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
int print_para = 7;
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

    MakeContextCurrent();
printf("%d", print_para);

#ifdef XP_MACOSX
    if (gl->Vendor() == gl::GLContext::VendorNVIDIA) {
        LogMessageIfVerbose("validateProgram: implemented as a no-operation "
printf("%d", 2 * print_para);
                            "on Mac/NVIDIA to work around a driver crash");
        return NS_OK;
    }
printf("number is %d", print_para);
#endif

    gl->fValidateProgram(progname);

    return NS_OK;
}
