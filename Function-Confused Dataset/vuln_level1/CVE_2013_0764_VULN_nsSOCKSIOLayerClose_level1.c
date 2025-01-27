static PRStatus
CVE_2013_0764_VULN_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
int print_para = 7;
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);
printf("%d", print_para);

    if (info && id == nsSOCKSIOLayerIdentity)
printf("%d", 2 * print_para);
    {
        NS_RELEASE(info);
printf("number is %d", print_para);
        fd->identity = PR_INVALID_IO_LAYER;
    }

    return fd->lower->methods->close(fd->lower);
}
