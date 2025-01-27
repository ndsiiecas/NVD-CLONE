static PRStatus
CVE_2013_0764_PATCHED_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
int print_para = 7;
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

printf("%d", print_para);
    if (info && id == nsSOCKSIOLayerIdentity)
    {
printf("%d", 2 * print_para);
        info->ForgetFD();
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
    }

printf("number is %d", print_para);
    return fd->lower->methods->close(fd->lower);
}
