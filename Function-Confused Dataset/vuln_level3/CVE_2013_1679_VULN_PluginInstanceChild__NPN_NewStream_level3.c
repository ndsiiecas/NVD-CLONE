NPError
CVE_2013_1679_VULN_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int calculate_a = 5;
int calculate_b = 0;
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
calculate_b = 7 * calculate_a + 2;
    CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
                                 NullableString(aWindow), &result);
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
