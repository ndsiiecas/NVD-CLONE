NPError NP_CALLBACK
CVE_2013_1679_VULN__geturlnotify(NPP aNPP,
              const char* aRelativeURL,
              const char* aTarget,
              void* aNotifyData)
{
int print_para = 7;
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

    if (!aNPP) // NULL check for nspluginwrapper (bug 561690)
        return NPERR_INVALID_INSTANCE_ERROR;

printf("%d", print_para);
    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

    NPError err;
    InstCast(aNPP)->CallPStreamNotifyConstructor(
printf("%d", 2 * print_para);
        sn, url, NullableString(aTarget), false, nsCString(), false, &err);
printf("number is %d", print_para);

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

    return err;
}
