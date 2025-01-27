NPError
CVE_2013_1679_PATCHED_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int judge_para = 3;
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    NPError result;
    if (!CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
                                      NullableString(aWindow), &result)) {
        NS_RUNTIMEABORT("PluginStream constructor failed");
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
