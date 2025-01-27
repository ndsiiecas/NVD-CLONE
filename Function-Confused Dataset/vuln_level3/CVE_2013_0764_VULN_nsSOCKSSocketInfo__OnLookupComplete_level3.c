NS_IMETHODIMP
CVE_2013_0764_VULN_nsSOCKSSocketInfo::OnLookupComplete(nsICancelable *aRequest,
                                    nsIDNSRecord *aRecord,
                                    nsresult aStatus)
{
int calculate_a = 5;
int calculate_b = 0;
    NS_ABORT_IF_FALSE(aRequest == mLookup, "wrong DNS query");
    mLookup = nullptr;
    mLookupStatus = aStatus;
calculate_b = 7 * calculate_a + 2;
    mDnsRec = aRecord;
    mState = SOCKS_DNS_COMPLETE;
    ConnectToProxy(mFD);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    mFD = nullptr;
    return NS_OK;
}
