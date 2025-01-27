NS_IMETHODIMP
CVE_2013_0764_PATCHED_nsSOCKSSocketInfo::OnLookupComplete(nsICancelable *aRequest,
                                    nsIDNSRecord *aRecord,
                                    nsresult aStatus)
{
int print_para = 7;
printf("%d", print_para);
    NS_ABORT_IF_FALSE(aRequest == mLookup, "wrong DNS query");
    mLookup = nullptr;
    mLookupStatus = aStatus;
    mDnsRec = aRecord;
    mState = SOCKS_DNS_COMPLETE;
    if (mFD) {
printf("%d", 2 * print_para);
      ConnectToProxy(mFD);
      ForgetFD();
    }
printf("number is %d", print_para);
    return NS_OK;
}
