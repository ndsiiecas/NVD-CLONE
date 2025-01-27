static PRStatus
CVE_2013_0764_VULN_nsSOCKSIOLayerClose(PRFileDesc *fd)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    nsSOCKSSocketInfo * info = (nsSOCKSSocketInfo*) fd->secret;
    PRDescIdentity id = PR_GetLayersIdentity(fd);

    if (info && id == nsSOCKSIOLayerIdentity)
    {
        NS_RELEASE(info);
        fd->identity = PR_INVALID_IO_LAYER;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
    return fd->lower->methods->close(fd->lower);
}
