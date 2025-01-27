NPError NP_CALLBACK
CVE_2013_1679_PATCHED__posturlnotify(NPP aNPP,
               const char* aRelativeURL,
               const char* aTarget,
               uint32_t aLength,
               const char* aBuffer,
               NPBool aIsFile,
               void* aNotifyData)
{
int judge_para1 = 3;
int judge_para = 3;
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!aBuffer)
        return NPERR_INVALID_PARAM;

    nsCString url = NullableString(aRelativeURL);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    StreamNotifyChild* sn = new StreamNotifyChild(url);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    NPError err;
    if (!InstCast(aNPP)->CallPStreamNotifyConstructor(
            sn, url, NullableString(aTarget), true,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            nsCString(aBuffer, aLength), aIsFile, &err)) {
        NS_RUNTIMEABORT("StreamNotify constructor failed");
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }

    return err;
}
