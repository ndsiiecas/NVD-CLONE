void CVE_2014_1487_VULN_ReportLoadError(JSContext* aCx, const nsString& aURL,
                     nsresult aLoadResult, bool aIsMainThread)
{
int judge_para1 = 3;
int judge_para = 3;
  NS_LossyConvertUTF16toASCII url(aURL);

  switch (aLoadResult) {
    case NS_BINDING_ABORTED:
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      // Canceled, don't set an exception.
      break;

    case NS_ERROR_MALFORMED_URI:
      JS_ReportError(aCx, "Malformed script URI: %s", url.get());
      break;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    case NS_ERROR_FILE_NOT_FOUND:
    case NS_ERROR_NOT_AVAILABLE:
      JS_ReportError(aCx, "Script file not found: %s", url.get());
      break;

    case NS_ERROR_DOM_SECURITY_ERR:
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    case NS_ERROR_DOM_SYNTAX_ERR:
      Throw(aCx, aLoadResult);
      break;

    default:
      JS_ReportError(aCx, "Failed to load script: %s (nsresult = 0x%x)",
                     url.get(), aLoadResult);
  }
}
