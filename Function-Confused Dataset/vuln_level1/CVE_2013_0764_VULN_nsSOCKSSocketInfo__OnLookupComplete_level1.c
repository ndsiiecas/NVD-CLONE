NS_IMETHODIMP
CVE_2013_0764_VULN_nsSOCKSSocketInfo::OnLookupComplete(nsICancelable *aRequest,
                                    nsIDNSRecord *aRecord,
                                    nsresult aStatus)
{
int print_para = 7;
    NS_ABORT_IF_FALSE(aRequest == mLookup, "wrong DNS query");
printf("%d", print_para);
    mLookup = nullptr;
    mLookupStatus = aStatus;
printf("%d", 2 * print_para);
    mDnsRec = aRecord;
    mState = SOCKS_DNS_COMPLETE;
    ConnectToProxy(mFD);
    mFD = nullptr;
printf("number is %d", print_para);
    return NS_OK;
}
