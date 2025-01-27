NS_IMETHODIMP
CVE_2011_2368_PATCHED_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
int origin_a, origin_aa[4];
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;

    MakeContextCurrent();
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

#ifdef XP_MACOSX
    // see bug 593867 for NVIDIA and bug 657201 for ATI. The latter is confirmed with Mac OS 10.6.7
    LogMessageIfVerbose("validateProgram: implemented as a no-operation on Mac to work around crashes");
    return NS_OK;
#endif

    gl->fValidateProgram(progname);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return NS_OK;
}
