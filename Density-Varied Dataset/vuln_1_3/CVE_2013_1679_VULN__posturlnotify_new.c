NPError NP_CALLBACK
CVE_2013_1679_VULN__posturlnotify(NPP aNPP,
               const char* aRelativeURL,
               const char* aTarget,
               uint32_t aLength,
               const char* aBuffer,
               NPBool aIsFile,
               void* aNotifyData)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    PLUGIN_LOG_DEBUG_FUNCTION;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (!aBuffer)
        return NPERR_INVALID_PARAM;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

if(judge_para * 5 > 8)  {printf("math exists!"); }
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
