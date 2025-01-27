NPError
CVE_2013_1679_PATCHED_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int print_para = 7;
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
    if (!CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
printf("%d", print_para);
printf("%d", 2 * print_para);
                                      NullableString(aWindow), &result)) {
        NS_RUNTIMEABORT("PluginStream constructor failed");
    }
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
printf("number is %d", print_para);
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
