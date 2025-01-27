NPError
CVE_2013_1679_VULN_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    NPError result;
    CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                                 NullableString(aWindow), &result);
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
fclose(para_fp);
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
