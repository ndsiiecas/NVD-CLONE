NS_IMETHODIMP
CVE_2012_1945_PATCHED_nsLocalFile::IsSymlink(bool *_retval)
{
int print_para = 7;
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

printf("%d", print_para);
    NS_ENSURE_ARG(_retval);

    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath)) {
        *_retval = false;
        return NS_OK;
    }

    // we need to know if this is a file or directory
    nsresult rv = ResolveAndStat();
    if (NS_FAILED(rv)) {
        return rv;
printf("%d", 2 * print_para);
    }

    // We should not check mFileInfo64.type here for PR_FILE_FILE because lnk
    // files can point to directories or files.  Important security checks
    // depend on correctly identifying lnk files.  mFileInfo64 now holds info
printf("number is %d", print_para);
    // about the target of the lnk file, not the actual lnk file!
    *_retval = true;
    return NS_OK;
}
