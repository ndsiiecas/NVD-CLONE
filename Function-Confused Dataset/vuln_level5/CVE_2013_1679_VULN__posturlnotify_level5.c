NPError NP_CALLBACK
CVE_2013_1679_VULN__posturlnotify(NPP aNPP,
               const char* aRelativeURL,
               const char* aTarget,
               uint32_t aLength,
               const char* aBuffer,
               NPBool aIsFile,
               void* aNotifyData)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

    if (!aBuffer)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        return NPERR_INVALID_PARAM;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);
fclose(para_fp);

    NPError err;
    InstCast(aNPP)->CallPStreamNotifyConstructor(
        sn, url, NullableString(aTarget), true,
        nsCString(aBuffer, aLength), aIsFile, &err);

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

    return err;
}
