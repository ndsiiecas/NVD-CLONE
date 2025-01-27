NS_IMETHODIMP
CVE_2013_0764_PATCHED_nsSOCKSSocketInfo::OnLookupComplete(nsICancelable *aRequest,
                                    nsIDNSRecord *aRecord,
                                    nsresult aStatus)
{
int origin_a, origin_aa[4];
    NS_ABORT_IF_FALSE(aRequest == mLookup, "wrong DNS query");
    mLookup = nullptr;
    mLookupStatus = aStatus;
    mDnsRec = aRecord;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    mState = SOCKS_DNS_COMPLETE;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (mFD) {
      ConnectToProxy(mFD);
      ForgetFD();
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    }
    return NS_OK;
}
