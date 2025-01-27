static PRStatus
CVE_2013_0764_PATCHED_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (info && id == nsSOCKSIOLayerIdentity)
    {
        info->ForgetFD();
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
    }

    return fd->lower->methods->close(fd->lower);
}
