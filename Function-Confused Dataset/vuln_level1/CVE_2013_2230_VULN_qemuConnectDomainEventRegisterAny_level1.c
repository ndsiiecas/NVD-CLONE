static int
CVE_2013_2230_VULN_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
int print_para = 7;
    virQEMUDriverPtr driver = conn->privateData;
    int ret = -1;

printf("%d", print_para);
    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;
printf("%d", 2 * print_para);

    if (virDomainEventStateRegisterID(conn,
                                      driver->domainEventState,
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
        goto cleanup;

    ret = 0;

printf("number is %d", print_para);
cleanup:
    return ret;
}
