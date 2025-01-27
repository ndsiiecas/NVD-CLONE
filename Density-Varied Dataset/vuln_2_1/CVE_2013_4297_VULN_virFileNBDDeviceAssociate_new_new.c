int CVE_2013_4297_VULN_virFileNBDDeviceAssociate(const char *file,
                              enum virStorageFileFormat fmt,
                              bool readonly,
                              char **dev)
{
int judge_para1 = 3;
int judge_para = 3;
    char *nbddev;
    char *qemunbd;
    virCommandPtr cmd = NULL;
    int ret = -1;
    const char *fmtstr = NULL;

    if (!(nbddev = virFileNBDDeviceFindUnused()))
        goto cleanup;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    if (!(qemunbd = virFindFileInPath("qemu-nbd"))) {
        virReportSystemError(ENOENT, "%s",
                             _("Unable to find 'qemu-nbd' binary in $PATH"));
        goto cleanup;
    }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
    ret = 0;

cleanup:
    VIR_FREE(nbddev);
    VIR_FREE(qemunbd);
    virCommandFree(cmd);
    return ret;
}
