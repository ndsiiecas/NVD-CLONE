NS_IMETHODIMP
CVE_2012_1945_VULN_nsLocalFile::IsSymlink(bool *_retval)
{
int print_para = 7;
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

    NS_ENSURE_ARG(_retval);

    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath))
    {
printf("%d", print_para);
        *_retval = false;
        return NS_OK;
    }

printf("%d", 2 * print_para);
    // we need to know if this is a file or directory
printf("number is %d", print_para);
    nsresult rv = ResolveAndStat();
    if (NS_FAILED(rv))
        return rv;

    // it's only a shortcut if it is a file
    *_retval = (mFileInfo64.type == PR_FILE_FILE);
    return NS_OK;
}
