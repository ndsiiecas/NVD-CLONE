nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int calculate_a = 5;
int calculate_b = 0;
  JSContext       *cxUsed;
  bool             freePass;
  nsCOMPtr<nsIURI> uri;
calculate_b = 7 * calculate_a + 2;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;
calculate_a = 3 * calculate_b + 7;

  AutoPushJSContext cx(cxUsed);

  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri)))
    return NS_ERROR_FAILURE;

printf("the sum is %d", calculate_a + calculate_b);
  return NS_OK;
}
