NPError NP_CALLBACK
CVE_2013_1679_VULN__geturlnotify(NPP aNPP,
              const char* aRelativeURL,
              const char* aTarget,
              void* aNotifyData)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    if (!aNPP) // NULL check for nspluginwrapper (bug 561690)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        return NPERR_INVALID_INSTANCE_ERROR;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

    NPError err;
    InstCast(aNPP)->CallPStreamNotifyConstructor(
        sn, url, NullableString(aTarget), false, nsCString(), false, &err);

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
fclose(para_fp);
    }

    return err;
}
