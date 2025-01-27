static PRStatus
CVE_2013_0764_PATCHED_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

    if (info && id == nsSOCKSIOLayerIdentity)
    {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        info->ForgetFD();
fclose(para_fp);
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
    }

    return fd->lower->methods->close(fd->lower);
}
