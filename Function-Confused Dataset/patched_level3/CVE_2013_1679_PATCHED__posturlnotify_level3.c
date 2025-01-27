NPError NP_CALLBACK
CVE_2013_1679_PATCHED__posturlnotify(NPP aNPP,
               const char* aRelativeURL,
               const char* aTarget,
               uint32_t aLength,
               const char* aBuffer,
               NPBool aIsFile,
               void* aNotifyData)
{
int calculate_a = 5;
int calculate_b = 0;
    PLUGIN_LOG_DEBUG_FUNCTION;
calculate_b = 7 * calculate_a + 2;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

calculate_a = 3 * calculate_b + 7;
    if (!aBuffer)
        return NPERR_INVALID_PARAM;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

    NPError err;
    if (!InstCast(aNPP)->CallPStreamNotifyConstructor(
            sn, url, NullableString(aTarget), true,
            nsCString(aBuffer, aLength), aIsFile, &err)) {
        NS_RUNTIMEABORT("StreamNotify constructor failed");
    }

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
printf("the sum is %d", calculate_a + calculate_b);
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

    return err;
}
