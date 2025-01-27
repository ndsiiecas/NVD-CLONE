NPError NP_CALLBACK
CVE_2013_1679_VULN__geturlnotify(NPP aNPP,
              const char* aRelativeURL,
              const char* aTarget,
              void* aNotifyData)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    PLUGIN_LOG_DEBUG_FUNCTION;
    ENSURE_PLUGIN_THREAD(NPERR_INVALID_PARAM);

    if (!aNPP) // NULL check for nspluginwrapper (bug 561690)
        return NPERR_INVALID_INSTANCE_ERROR;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    nsCString url = NullableString(aRelativeURL);
    StreamNotifyChild* sn = new StreamNotifyChild(url);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    NPError err;
    InstCast(aNPP)->CallPStreamNotifyConstructor(
        sn, url, NullableString(aTarget), false, nsCString(), false, &err);

    if (NPERR_NO_ERROR == err) {
        // If NPN_PostURLNotify fails, the parent will immediately send us
        // a PStreamNotifyDestructor, which should not call NPP_URLNotify.
        sn->SetValid(aNotifyData);
    }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return err;
}
