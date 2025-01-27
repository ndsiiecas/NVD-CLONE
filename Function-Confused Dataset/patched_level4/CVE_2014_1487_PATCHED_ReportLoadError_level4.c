void CVE_2014_1487_PATCHED_ReportLoadError(JSContext* aCx, const nsString& aURL,
                     nsresult aLoadResult, bool aIsMainThread)
{
int origin_a, origin_aa[4];
  NS_LossyConvertUTF16toASCII url(aURL);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  switch (aLoadResult) {
    case NS_BINDING_ABORTED:
      // Canceled, don't set an exception.
      break;

    case NS_ERROR_MALFORMED_URI:
      JS_ReportError(aCx, "Malformed script URI: %s", url.get());
      break;

    case NS_ERROR_FILE_NOT_FOUND:
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    case NS_ERROR_NOT_AVAILABLE:
      JS_ReportError(aCx, "Script file not found: %s", url.get());
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      break;

    case NS_ERROR_DOM_SECURITY_ERR:
    case NS_ERROR_DOM_SYNTAX_ERR:
      Throw(aCx, aLoadResult);
      break;

    default:
      JS_ReportError(aCx, "Failed to load script (nsresult = 0x%x)", aLoadResult);
  }
}
