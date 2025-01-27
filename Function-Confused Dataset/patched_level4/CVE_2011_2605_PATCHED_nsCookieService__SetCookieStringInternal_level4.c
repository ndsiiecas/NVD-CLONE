void
CVE_2011_2605_PATCHED_nsCookieService::SetCookieStringInternal(nsIURI          *aHostURI,
                                         bool             aIsForeign,
                                         const nsCString &aCookieHeader,
                                         const nsCString &aServerTime,
                                         PRBool           aFromHttp) 
{
int origin_a, origin_aa[4];
  NS_ASSERTION(aHostURI, "null host!");

  if (!mDBState) {
    NS_WARNING("No DBState! Profile already closed?");
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    return;
  }

  // get the base domain for the host URI.
  // e.g. for "www.bbc.co.uk", this would be "bbc.co.uk".
  // file:// URI's (i.e. with an empty host) are allowed, but any other
  // scheme must have a non-empty host. A trailing dot in the host
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
  // is acceptable.
  PRBool requireHostMatch;
  nsCAutoString baseDomain;
  nsresult rv = GetBaseDomain(aHostURI, baseDomain, requireHostMatch);
  if (NS_FAILED(rv)) {
    COOKIE_LOGFAILURE(SET_COOKIE, aHostURI, aCookieHeader, 
                      "couldn't get base domain from URI");
    return;
  }

  // check default prefs
  CookieStatus cookieStatus = CheckPrefs(aHostURI, aIsForeign, baseDomain,
                                         requireHostMatch, aCookieHeader.get());
  // fire a notification if cookie was rejected (but not if there was an error)
  switch (cookieStatus) {
  case STATUS_REJECTED:
    NotifyRejected(aHostURI);
  case STATUS_REJECTED_WITH_ERROR:
    return;
  default:
    break;
  }

  // parse server local time. this is not just done here for efficiency
  // reasons - if there's an error parsing it, and we need to default it
  // to the current time, we must do it here since the current time in
  // SetCookieInternal() will change for each cookie processed (e.g. if the
  // user is prompted).
  PRTime tempServerTime;
  PRInt64 serverTime;
  PRStatus result = PR_ParseTimeString(aServerTime.get(), PR_TRUE,
                                       &tempServerTime);
  if (result == PR_SUCCESS) {
    serverTime = tempServerTime / PR_USEC_PER_SEC;
  } else {
    serverTime = PR_Now() / PR_USEC_PER_SEC;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }

  // process each cookie in the header
  nsDependentCString cookieHeader(aCookieHeader);
  while (SetCookieInternal(aHostURI, baseDomain, requireHostMatch,
                           cookieStatus, cookieHeader, serverTime, aFromHttp)) {
    // document.cookie can only set one cookie at a time
    if (!aFromHttp)
      break;
  }
}
