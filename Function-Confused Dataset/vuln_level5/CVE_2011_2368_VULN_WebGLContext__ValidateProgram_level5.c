NS_IMETHODIMP
CVE_2011_2368_VULN_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    MakeContextCurrent();

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
#ifdef XP_MACOSX
fclose(para_fp);
    if (gl->Vendor() == gl::GLContext::VendorNVIDIA) {
        LogMessageIfVerbose("validateProgram: implemented as a no-operation "
                            "on Mac/NVIDIA to work around a driver crash");
        return NS_OK;
    }
#endif

    gl->fValidateProgram(progname);

    return NS_OK;
}
