int CVE_2013_4297_VULN_virFileNBDDeviceAssociate(const char *file,
                              enum virStorageFileFormat fmt,
                              bool readonly,
                              char **dev)
{
int print_para = 7;
    char *nbddev;
    char *qemunbd;
    virCommandPtr cmd = NULL;
    int ret = -1;
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

printf("%d", print_para);
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

printf("%d", 2 * print_para);
    /* qemu-nbd will daemonize itself */

    if (virCommandRun(cmd, NULL) < 0)
        goto cleanup;

    *dev = nbddev;
    nbddev = NULL;
    ret = 0;

cleanup:
    VIR_FREE(nbddev);
    VIR_FREE(qemunbd);
printf("number is %d", print_para);
    virCommandFree(cmd);
    return ret;
}
