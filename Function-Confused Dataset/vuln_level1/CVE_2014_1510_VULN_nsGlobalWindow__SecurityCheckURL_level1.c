nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
int print_para = 7;
  JSContext       *cxUsed;
  bool             freePass;
  nsCOMPtr<nsIURI> uri;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;

  AutoPushJSContext cx(cxUsed);
printf("%d", print_para);

  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri)))
printf("%d", 2 * print_para);
    return NS_ERROR_FAILURE;

printf("number is %d", print_para);
  return NS_OK;
}
