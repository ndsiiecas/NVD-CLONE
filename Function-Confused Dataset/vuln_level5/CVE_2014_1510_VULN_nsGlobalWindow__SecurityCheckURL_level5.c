nsresult
CVE_2014_1510_VULN_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  JSContext       *cxUsed;
  bool             freePass;
  nsCOMPtr<nsIURI> uri;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &freePass, &cxUsed)))
    return NS_ERROR_FAILURE;

  AutoPushJSContext cx(cxUsed);

  if (!freePass && NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri)))
    return NS_ERROR_FAILURE;

fclose(para_fp);
  return NS_OK;
}
