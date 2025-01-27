NS_IMETHODIMP
CVE_2012_1945_VULN_nsLocalFile::IsSymlink(bool *_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

    NS_ENSURE_ARG(_retval);

    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath))
    {
        *_retval = false;
        return NS_OK;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }

    // we need to know if this is a file or directory
    nsresult rv = ResolveAndStat();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if (NS_FAILED(rv))
        return rv;
fclose(para_fp);

    // it's only a shortcut if it is a file
    *_retval = (mFileInfo64.type == PR_FILE_FILE);
    return NS_OK;
}
