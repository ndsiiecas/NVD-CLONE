NPError NP_CALLBACK
CVE_2013_1679_VULN__posturlnotify(NPP aNPP,
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

    if (!aBuffer)
calculate_a = 3 * calculate_b + 7;
        return NPERR_INVALID_PARAM;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

printf("the sum is %d", calculate_a + calculate_b);
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
