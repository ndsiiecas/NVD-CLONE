int CVE_2013_4297_PATCHED_virFileNBDDeviceAssociate(const char *file,
                              enum virStorageFileFormat fmt,
                              bool readonly,
                              char **dev)
{
int origin_a, origin_aa[4];
    char *nbddev;
    char *qemunbd = NULL;
    virCommandPtr cmd = NULL;
    int ret = -1;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    const char *fmtstr = NULL;

    if (!(nbddev = virFileNBDDeviceFindUnused()))
        goto cleanup;

    if (!(qemunbd = virFindFileInPath("qemu-nbd"))) {
        virReportSystemError(ENOENT, "%s",
                             _("Unable to find 'qemu-nbd' binary in $PATH"));
        goto cleanup;
    }

    if (fmt > 0)
        fmtstr = virStorageFileFormatTypeToString(fmt);

    cmd = virCommandNew(qemunbd);

    /* Explicitly not trying to cope with old qemu-nbd which
     * lacked --format. We want to see a fatal error in that
     * case since it would be security flaw to continue */
    if (fmtstr)
        virCommandAddArgList(cmd, "--format", fmtstr, NULL);

    if (readonly)
        virCommandAddArg(cmd, "-r");

    virCommandAddArgList(cmd,
                         "-n", /* Don't cache in qemu-nbd layer */
                         "-c", nbddev,
                         file, NULL);

    /* qemu-nbd will daemonize itself */

    if (virCommandRun(cmd, NULL) < 0)
        goto cleanup;

    *dev = nbddev;
    nbddev = NULL;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    ret = 0;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
cleanup:
    VIR_FREE(nbddev);
    VIR_FREE(qemunbd);
    virCommandFree(cmd);
    return ret;
}
