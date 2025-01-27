NS_IMETHODIMP
CVE_2011_2368_PATCHED_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

    MakeContextCurrent();

#ifdef XP_MACOSX
    // see bug 593867 for NVIDIA and bug 657201 for ATI. The latter is confirmed with Mac OS 10.6.7
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    LogMessageIfVerbose("validateProgram: implemented as a no-operation on Mac to work around crashes");
    return NS_OK;
#endif

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    gl->fValidateProgram(progname);

fclose(para_fp);
    return NS_OK;
}
