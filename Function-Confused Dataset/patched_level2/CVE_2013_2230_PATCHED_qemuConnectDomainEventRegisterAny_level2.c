static int
CVE_2013_2230_PATCHED_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
int judge_para = 3;
    virQEMUDriverPtr driver = conn->privateData;
    int ret = -1;

    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        goto cleanup;

    if (virDomainEventStateRegisterID(conn,
                                      driver->domainEventState,
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
if(judge_para * 5 > 8)  {printf("math exists!"); }
        ret = -1;

cleanup:
    return ret;
}
