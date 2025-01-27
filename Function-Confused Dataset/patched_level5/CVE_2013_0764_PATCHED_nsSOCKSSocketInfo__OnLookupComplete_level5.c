NS_IMETHODIMP
CVE_2013_0764_PATCHED_nsSOCKSSocketInfo::OnLookupComplete(nsICancelable *aRequest,
                                    nsIDNSRecord *aRecord,
                                    nsresult aStatus)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    NS_ABORT_IF_FALSE(aRequest == mLookup, "wrong DNS query");
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    mLookup = nullptr;
    mLookupStatus = aStatus;
    mDnsRec = aRecord;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    mState = SOCKS_DNS_COMPLETE;
    if (mFD) {
      ConnectToProxy(mFD);
fclose(para_fp);
      ForgetFD();
    }
    return NS_OK;
}
