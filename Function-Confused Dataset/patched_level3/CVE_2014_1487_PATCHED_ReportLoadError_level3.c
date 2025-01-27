void CVE_2014_1487_PATCHED_ReportLoadError(JSContext* aCx, const nsString& aURL,
                     nsresult aLoadResult, bool aIsMainThread)
{
int calculate_a = 5;
int calculate_b = 0;
  NS_LossyConvertUTF16toASCII url(aURL);

  switch (aLoadResult) {
    case NS_BINDING_ABORTED:
      // Canceled, don't set an exception.
calculate_b = 7 * calculate_a + 2;
      break;

    case NS_ERROR_MALFORMED_URI:
      JS_ReportError(aCx, "Malformed script URI: %s", url.get());
      break;

calculate_a = 3 * calculate_b + 7;
    case NS_ERROR_FILE_NOT_FOUND:
    case NS_ERROR_NOT_AVAILABLE:
      JS_ReportError(aCx, "Script file not found: %s", url.get());
      break;

    case NS_ERROR_DOM_SECURITY_ERR:
    case NS_ERROR_DOM_SYNTAX_ERR:
      Throw(aCx, aLoadResult);
      break;
printf("the sum is %d", calculate_a + calculate_b);

    default:
      JS_ReportError(aCx, "Failed to load script (nsresult = 0x%x)", aLoadResult);
  }
}
