static PRStatus
CVE_2013_0764_PATCHED_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
int origin_a, origin_aa[4];
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if (info && id == nsSOCKSIOLayerIdentity)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        info->ForgetFD();
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
    }

    return fd->lower->methods->close(fd->lower);
}
