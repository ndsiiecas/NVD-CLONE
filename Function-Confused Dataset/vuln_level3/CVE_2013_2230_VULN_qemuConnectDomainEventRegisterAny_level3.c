static int
CVE_2013_2230_VULN_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
int calculate_a = 5;
int calculate_b = 0;
    virQEMUDriverPtr driver = conn->privateData;
    int ret = -1;

calculate_b = 7 * calculate_a + 2;
    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;

    if (virDomainEventStateRegisterID(conn,
                                      driver->domainEventState,
calculate_a = 3 * calculate_b + 7;
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
        goto cleanup;

    ret = 0;
printf("the sum is %d", calculate_a + calculate_b);

cleanup:
    return ret;
}
