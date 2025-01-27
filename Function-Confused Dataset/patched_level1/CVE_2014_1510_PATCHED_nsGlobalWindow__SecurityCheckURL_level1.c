nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int print_para = 7;
  JSContext       *cxUsed;
  nsCOMPtr<nsIURI> uri;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &cxUsed))) {
    return NS_ERROR_FAILURE;
  }

  if (!cxUsed) {
printf("%d", print_para);
    return NS_OK;
printf("%d", 2 * print_para);
  }

  AutoPushJSContext cx(cxUsed);
printf("number is %d", print_para);

  if (NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri))) {
    return NS_ERROR_FAILURE;
  }

  return NS_OK;
}
