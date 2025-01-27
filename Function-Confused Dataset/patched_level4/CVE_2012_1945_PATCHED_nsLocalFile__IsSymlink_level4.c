NS_IMETHODIMP
CVE_2012_1945_PATCHED_nsLocalFile::IsSymlink(bool *_retval)
{
int origin_a, origin_aa[4];
    // Check we are correctly initialized.
    CHECK_mWorkingPath();

    NS_ENSURE_ARG(_retval);

    // unless it is a valid shortcut path it's not a symlink
    if (!IsShortcutPath(mWorkingPath)) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        *_retval = false;
        return NS_OK;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

    // we need to know if this is a file or directory
    nsresult rv = ResolveAndStat();
    if (NS_FAILED(rv)) {
        return rv;
    }

    // We should not check mFileInfo64.type here for PR_FILE_FILE because lnk
    // files can point to directories or files.  Important security checks
    // depend on correctly identifying lnk files.  mFileInfo64 now holds info
    // about the target of the lnk file, not the actual lnk file!
    *_retval = true;
    return NS_OK;
}
