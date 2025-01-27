NPError NP_CALLBACK
CVE_2013_1679_PATCHED__geturlnotify(NPP aNPP,
              const char* aRelativeURL,
              const char* aTarget,
              void* aNotifyData)
{
int judge_para1 = 3;
int judge_para = 3;
    PLUGIN_LOG_DEBUG_FUNCTION;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

    if (!aNPP) // NULL check for nspluginwrapper (bug 561690)
        return NPERR_INVALID_INSTANCE_ERROR;

    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    NPError err;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if (!InstCast(aNPP)->CallPStreamNotifyConstructor(
           sn, url, NullableString(aTarget), false, nsCString(), false, &err)) {
        NS_RUNTIMEABORT("StreamNotify constructor failed");
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }

    return err;
}
