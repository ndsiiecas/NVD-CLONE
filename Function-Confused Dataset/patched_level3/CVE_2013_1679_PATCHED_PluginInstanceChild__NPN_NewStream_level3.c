NPError
CVE_2013_1679_PATCHED_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int calculate_a = 5;
int calculate_b = 0;
    AssertPluginThread();

    PluginStreamChild* ps = new PluginStreamChild();

calculate_b = 7 * calculate_a + 2;
    NPError result;
calculate_a = 3 * calculate_b + 7;
    if (!CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
                                      NullableString(aWindow), &result)) {
        NS_RUNTIMEABORT("PluginStream constructor failed");
    }
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
printf("the sum is %d", calculate_a + calculate_b);
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
