void CVE_2014_1487_VULN_ReportLoadError(JSContext* aCx, const nsString& aURL,
                     nsresult aLoadResult, bool aIsMainThread)
{
  NS_LossyConvertUTF16toASCII url(aURL);

  switch (aLoadResult) {
    case NS_BINDING_ABORTED:
      // Canceled, don't set an exception.
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
      break;

    case NS_ERROR_MALFORMED_URI:
      JS_ReportError(aCx, "Malformed script URI: %s", url.get());
      break;

    case NS_ERROR_FILE_NOT_FOUND:
    case NS_ERROR_NOT_AVAILABLE:
      JS_ReportError(aCx, "Script file not found: %s", url.get());
      break;

    case NS_ERROR_DOM_SECURITY_ERR:
    case NS_ERROR_DOM_SYNTAX_ERR:
      Throw(aCx, aLoadResult);
      break;

    default:
      JS_ReportError(aCx, "Failed to load script: %s (nsresult = 0x%x)",
                     url.get(), aLoadResult);
  }
}
