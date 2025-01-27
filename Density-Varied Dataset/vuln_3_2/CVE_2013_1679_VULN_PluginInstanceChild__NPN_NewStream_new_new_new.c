NPError
CVE_2013_1679_VULN_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    AssertPluginThread();
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
    CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                                 NullableString(aWindow), &result);
    if (NPERR_NO_ERROR != result) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }

    *aStream = &ps->mStream;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    return NPERR_NO_ERROR;
}
