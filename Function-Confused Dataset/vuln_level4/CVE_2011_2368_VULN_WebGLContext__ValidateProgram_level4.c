NS_IMETHODIMP
CVE_2011_2368_VULN_WebGLContext::ValidateProgram(nsIWebGLProgram *pobj)
{
int origin_a, origin_aa[4];
    WebGLuint progname;
    if (!GetGLName<WebGLProgram>("validateProgram", pobj, &progname))
        return NS_OK;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    MakeContextCurrent();

#ifdef XP_MACOSX
    if (gl->Vendor() == gl::GLContext::VendorNVIDIA) {
        LogMessageIfVerbose("validateProgram: implemented as a no-operation "
                            "on Mac/NVIDIA to work around a driver crash");
        return NS_OK;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }
#endif
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    gl->fValidateProgram(progname);

    return NS_OK;
}
