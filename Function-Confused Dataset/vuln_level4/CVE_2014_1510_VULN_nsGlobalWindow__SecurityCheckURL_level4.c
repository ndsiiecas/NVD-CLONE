nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int origin_a, origin_aa[4];
  JSContext       *cxUsed;
  bool             freePass;
  nsCOMPtr<nsIURI> uri;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;

  AutoPushJSContext cx(cxUsed);

  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri)))
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    return NS_ERROR_FAILURE;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  return NS_OK;
}
