NPError
CVE_2013_1679_VULN_PluginInstanceChild::NPN_NewStream(NPMIMEType aMIMEType, const char* aWindow,
                                   NPStream** aStream)
{
int origin_a, origin_aa[4];
    AssertPluginThread();

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    PluginStreamChild* ps = new PluginStreamChild();

    NPError result;
    CallPPluginStreamConstructor(ps, nsDependentCString(aMIMEType),
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                                 NullableString(aWindow), &result);
    if (NPERR_NO_ERROR != result) {
        *aStream = NULL;
        PPluginStreamChild::Call__delete__(ps, NPERR_GENERIC_ERROR, true);
        return result;
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    *aStream = &ps->mStream;
    return NPERR_NO_ERROR;
}
