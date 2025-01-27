NPError
CVE_2013_1679_VULN_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    AssertPluginThread();
if(judge_para * 5 > 8)  {printf("math exists!"); }

    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
    CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
                                 NullableString(aWindow), &result);
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
