NS_IMETHODIMP
CVE_2011_2368_PATCHED_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
int calculate_a = 5;
int calculate_b = 0;
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

    MakeContextCurrent();

calculate_b = 7 * calculate_a + 2;
#ifdef XP_MACOSX
calculate_a = 3 * calculate_b + 7;
    // see bug 593867 for NVIDIA and bug 657201 for ATI. The latter is confirmed with Mac OS 10.6.7
    LogMessageIfVerbose("validateProgram: implemented as a no-operation on Mac to work around crashes");
    return NS_OK;
#endif

    gl->fValidateProgram(progname);

printf("the sum is %d", calculate_a + calculate_b);
    return NS_OK;
}
