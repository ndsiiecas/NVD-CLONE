NS_IMETHODIMP
CVE_2012_1945_PATCHED_nsLocalFile::IsSymlink(bool *_retval)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

    NS_ENSURE_ARG(_retval);

    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath)) {
        *_retval = false;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        return NS_OK;
    }

    // we need to know if this is a file or directory
    nsresult rv = ResolveAndStat();
    if (NS_FAILED(rv)) {
        return rv;
    }

    // We should not check mFileInfo64.type here for PR_FILE_FILE because lnk
    // files can point to directories or files.  Important security checks
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // depend on correctly identifying lnk files.  mFileInfo64 now holds info
fclose(para_fp);
    // about the target of the lnk file, not the actual lnk file!
    *_retval = true;
    return NS_OK;
}
