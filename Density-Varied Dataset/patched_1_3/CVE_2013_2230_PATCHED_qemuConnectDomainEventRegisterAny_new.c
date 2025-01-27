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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;

    if (virDomainEventStateRegisterID(conn,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                                      driver->domainEventState,
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        ret = -1;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
cleanup:
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return ret;
}
