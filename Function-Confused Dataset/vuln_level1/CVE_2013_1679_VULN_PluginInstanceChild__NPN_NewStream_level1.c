NPError
CVE_2013_1679_VULN_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int print_para = 7;
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
    CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
                                 NullableString(aWindow), &result);
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
printf("%d", print_para);
        return result;
printf("%d", 2 * print_para);
printf("number is %d", print_para);
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
