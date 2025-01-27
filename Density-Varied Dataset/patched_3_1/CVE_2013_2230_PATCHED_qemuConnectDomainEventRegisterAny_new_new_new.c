static int
CVE_2013_2230_PATCHED_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    virQEMUDriverPtr driver = conn->privateData;
    int ret = -1;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;

    if (virDomainEventStateRegisterID(conn,
                                      driver->domainEventState,
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        ret = -1;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

cleanup:
    return ret;
}
