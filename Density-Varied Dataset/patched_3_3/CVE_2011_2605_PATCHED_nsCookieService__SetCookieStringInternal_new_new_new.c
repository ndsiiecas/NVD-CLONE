void
CVE_2011_2605_PATCHED_nsCookieService::SetCookieStringInternal(nsIURI          *aHostURI,
                                         bool             aIsForeign,
                                         const nsCString &aCookieHeader,
                                         const nsCString &aServerTime,
                                         PRBool           aFromHttp) 
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_ASSERTION(aHostURI, "null host!");

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!mDBState) {
    NS_WARNING("No DBState! Profile already closed?");
    return;
  }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // get the base domain for the host URI.
  // e.g. for "www.bbc.co.uk", this would be "bbc.co.uk".
  // file:// URI's (i.e. with an empty host) are allowed, but any other
  // scheme must have a non-empty host. A trailing dot in the host
  // is acceptable.
  PRBool requireHostMatch;
  nsCAutoString baseDomain;
  nsresult rv = GetBaseDomain(aHostURI, baseDomain, requireHostMatch);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  if (NS_FAILED(rv)) {
    COOKIE_LOGFAILURE(SET_COOKIE, aHostURI, aCookieHeader, 
                      "couldn't get base domain from URI");
    return;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    break;
  }

  // parse server local time. this is not just done here for efficiency
  // reasons - if there's an error parsing it, and we need to default it
  // to the current time, we must do it here since the current time in
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
  // SetCookieInternal() will change for each cookie processed (e.g. if the
  // user is prompted).
  PRTime tempServerTime;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
  PRInt64 serverTime;
  PRStatus result = PR_ParseTimeString(aServerTime.get(), PR_TRUE,
                                       &tempServerTime);
  if (result == PR_SUCCESS) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    serverTime = tempServerTime / PR_USEC_PER_SEC;
  } else {
    serverTime = PR_Now() / PR_USEC_PER_SEC;
  }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // process each cookie in the header
  nsDependentCString cookieHeader(aCookieHeader);
  while (SetCookieInternal(aHostURI, baseDomain, requireHostMatch,
                           cookieStatus, cookieHeader, serverTime, aFromHttp)) {
    // document.cookie can only set one cookie at a time
    if (!aFromHttp)
      break;
  }
}
