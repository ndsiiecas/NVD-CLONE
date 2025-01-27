static int
CVE_2013_2230_VULN_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
int origin_a, origin_aa[4];
    virQEMUDriverPtr driver = conn->privateData;
    int ret = -1;

    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (virDomainEventStateRegisterID(conn,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                                      driver->domainEventState,
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
        goto cleanup;

    ret = 0;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

cleanup:
    return ret;
}
