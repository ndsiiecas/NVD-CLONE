NPError NP_CALLBACK
CVE_2013_1679_PATCHED__posturlnotify(NPP aNPP,
               const char* aRelativeURL,
               const char* aTarget,
               uint32_t aLength,
               const char* aBuffer,
               NPBool aIsFile,
               void* aNotifyData)
{
int print_para = 7;
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

    if (!aBuffer)
        return NPERR_INVALID_PARAM;
printf("%d", print_para);

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);
printf("%d", 2 * print_para);

printf("number is %d", print_para);
    NPError err;
    if (!InstCast(aNPP)->CallPStreamNotifyConstructor(
            sn, url, NullableString(aTarget), true,
            nsCString(aBuffer, aLength), aIsFile, &err)) {
        NS_RUNTIMEABORT("StreamNotify constructor failed");
    }

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

    return err;
}
