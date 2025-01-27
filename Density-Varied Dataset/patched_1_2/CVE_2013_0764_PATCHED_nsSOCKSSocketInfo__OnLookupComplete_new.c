NS_IMETHODIMP
CVE_2013_0764_PATCHED_nsSOCKSSocketInfo::OnLookupComplete(nsICancelable *aRequest,
                                    nsIDNSRecord *aRecord,
                                    nsresult aStatus)
{
int judge_para = 3;
    NS_ABORT_IF_FALSE(aRequest == mLookup, "wrong DNS query");
    mLookup = nullptr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    mLookupStatus = aStatus;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    mDnsRec = aRecord;
    mState = SOCKS_DNS_COMPLETE;
    if (mFD) {
      ConnectToProxy(mFD);
      ForgetFD();
    }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return NS_OK;
}
