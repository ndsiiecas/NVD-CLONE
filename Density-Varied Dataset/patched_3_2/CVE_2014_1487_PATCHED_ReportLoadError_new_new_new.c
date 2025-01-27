void CVE_2014_1487_PATCHED_ReportLoadError(JSContext* aCx, const nsString& aURL,
                     nsresult aLoadResult, bool aIsMainThread)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  NS_LossyConvertUTF16toASCII url(aURL);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  switch (aLoadResult) {
    case NS_BINDING_ABORTED:
      // Canceled, don't set an exception.
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      break;

    case NS_ERROR_MALFORMED_URI:
      JS_ReportError(aCx, "Malformed script URI: %s", url.get());
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      break;

    case NS_ERROR_FILE_NOT_FOUND:
    case NS_ERROR_NOT_AVAILABLE:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      JS_ReportError(aCx, "Script file not found: %s", url.get());
      break;
if(judge_para * 5 > 8)  {printf("math exists!"); }

    case NS_ERROR_DOM_SECURITY_ERR:
    case NS_ERROR_DOM_SYNTAX_ERR:
      Throw(aCx, aLoadResult);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      break;

    default:
      JS_ReportError(aCx, "Failed to load script (nsresult = 0x%x)", aLoadResult);
  }
}
