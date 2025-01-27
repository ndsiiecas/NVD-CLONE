NPError NP_CALLBACK
CVE_2013_1679_PATCHED__geturlnotify(NPP aNPP,
              const char* aRelativeURL,
              const char* aTarget,
              void* aNotifyData)
{
int calculate_a = 5;
int calculate_b = 0;
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);
calculate_b = 7 * calculate_a + 2;

    if (!aNPP) // NULL check for nspluginwrapper (bug 561690)
        return NPERR_INVALID_INSTANCE_ERROR;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

    NPError err;
calculate_a = 3 * calculate_b + 7;
    if (!InstCast(aNPP)->CallPStreamNotifyConstructor(
           sn, url, NullableString(aTarget), false, nsCString(), false, &err)) {
printf("the sum is %d", calculate_a + calculate_b);
        NS_RUNTIMEABORT("StreamNotify constructor failed");
    }

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

    return err;
}
