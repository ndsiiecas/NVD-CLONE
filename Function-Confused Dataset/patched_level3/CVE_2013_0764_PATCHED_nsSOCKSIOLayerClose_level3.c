static PRStatus
CVE_2013_0764_PATCHED_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
int calculate_a = 5;
int calculate_b = 0;
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
calculate_b = 7 * calculate_a + 2;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

    if (info && id == nsSOCKSIOLayerIdentity)
    {
        info->ForgetFD();
calculate_a = 3 * calculate_b + 7;
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
printf("the sum is %d", calculate_a + calculate_b);
    }

    return fd->lower->methods->close(fd->lower);
}
