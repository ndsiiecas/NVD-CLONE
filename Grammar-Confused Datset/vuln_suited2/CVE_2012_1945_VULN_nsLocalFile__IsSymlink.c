NS_IMETHODIMP
CVE_2012_1945_VULN_nsLocalFile::IsSymlink(bool *_retval)
{
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

    NS_ENSURE_ARG(_retval);

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath))
    {
        *_retval = false;
        return NS_OK;
    }

    // we need to know if this is a file or directory
    nsresult rv = ResolveAndStat();
    if (NS_FAILED(rv))
        return rv;

    // it's only a shortcut if it is a file
    *_retval = (mFileInfo64.type == PR_FILE_FILE);
    return NS_OK;
}
