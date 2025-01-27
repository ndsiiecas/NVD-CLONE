static PRStatus
CVE_2013_0764_PATCHED_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

    if (info && id == nsSOCKSIOLayerIdentity)
    {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
        info->ForgetFD();
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
    }

    return fd->lower->methods->close(fd->lower);
}
