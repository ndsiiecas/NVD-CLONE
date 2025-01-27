static int
CVE_2013_2230_VULN_qemuConnectDomainEventRegisterAny(virConnectPtr conn,
                                  virDomainPtr dom,
                                  int eventID,
                                  virConnectDomainEventGenericCallback callback,
                                  void *opaque,
                                  virFreeCallback freecb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    virQEMUDriverPtr driver = conn->privateData;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    int ret = -1;

    if (virConnectDomainEventRegisterAnyEnsureACL(conn) < 0)
        goto cleanup;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (virDomainEventStateRegisterID(conn,
                                      driver->domainEventState,
                                      dom, eventID,
                                      callback, opaque, freecb, &ret) < 0)
fclose(para_fp);
        goto cleanup;

    ret = 0;

cleanup:
    return ret;
}
