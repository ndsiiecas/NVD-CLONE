static int
CVE_2013_2230_PATCHED_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
int print_para = 7;
    virQEMUDriverPtr driver = conn->privateData;
    int ret = -1;

    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;

    if (virDomainEventStateRegisterID(conn,
                                      driver->domainEventState,
printf("%d", print_para);
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
        ret = -1;

printf("%d", 2 * print_para);
printf("number is %d", print_para);
cleanup:
    return ret;
}
