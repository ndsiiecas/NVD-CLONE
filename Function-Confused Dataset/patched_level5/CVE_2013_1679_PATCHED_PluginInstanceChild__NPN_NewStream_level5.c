NPError
CVE_2013_1679_PATCHED_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
    if (!CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
                                      NullableString(aWindow), &result)) {
        NS_RUNTIMEABORT("PluginStream constructor failed");
    }
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    *aStream = &ps->mStream;
fclose(para_fp);
    return NPERR_NO_ERROR;
}
