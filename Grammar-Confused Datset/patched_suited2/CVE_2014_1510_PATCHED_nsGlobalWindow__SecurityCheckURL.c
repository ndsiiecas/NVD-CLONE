nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
  JSContext       *cxUsed;
  nsCOMPtr<nsIURI> uri;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &cxUsed))) {
    return NS_ERROR_FAILURE;
  }

  if (!cxUsed) {
    return NS_OK;
  }

  AutoPushJSContext cx(cxUsed);

  if (NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri))) {
    return NS_ERROR_FAILURE;
  }

  return NS_OK;
}
