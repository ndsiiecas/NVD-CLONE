NPError NP_CALLBACK
CVE_2013_1679_PATCHED__geturlnotify(NPP aNPP,
              const char* aRelativeURL,
              const char* aTarget,
              void* aNotifyData)
{
int print_para = 7;
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

    if (!aNPP) // NULL check for nspluginwrapper (bug 561690)
        return NPERR_INVALID_INSTANCE_ERROR;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

    NPError err;
    if (!InstCast(aNPP)->CallPStreamNotifyConstructor(
           sn, url, NullableString(aTarget), false, nsCString(), false, &err)) {
printf("%d", print_para);
        NS_RUNTIMEABORT("StreamNotify constructor failed");
    }
printf("%d", 2 * print_para);

printf("number is %d", print_para);
    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

    return err;
}
