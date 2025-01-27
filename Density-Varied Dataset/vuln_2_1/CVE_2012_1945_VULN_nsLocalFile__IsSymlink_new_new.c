NS_IMETHODIMP
CVE_2012_1945_VULN_nsLocalFile::IsSymlink(bool *_retval)
{
int judge_para1 = 3;
int judge_para = 3;
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

    NS_ENSURE_ARG(_retval);

    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath))
    {
        *_retval = false;
        return NS_OK;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    }

    // we need to know if this is a file or directory
    nsresult rv = ResolveAndStat();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (NS_FAILED(rv))
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        return rv;

    // it's only a shortcut if it is a file
    *_retval = (mFileInfo64.type == PR_FILE_FILE);
    return NS_OK;
}
