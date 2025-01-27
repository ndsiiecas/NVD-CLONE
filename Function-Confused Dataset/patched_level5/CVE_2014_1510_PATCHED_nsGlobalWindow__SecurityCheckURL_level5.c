nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::SecurityCheckURL(const char *aURL)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  JSContext       *cxUsed;
  nsCOMPtr<nsIURI> uri;

  if (NS_FAILED(BuildURIfromBase(aURL, getter_AddRefs(uri), &cxUsed))) {
    return NS_ERROR_FAILURE;
  }

  if (!cxUsed) {
    return NS_OK;
  }

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  AutoPushJSContext cx(cxUsed);

  if (NS_FAILED(nsContentUtils::GetSecurityManager()->
        CheckLoadURIFromScript(cx, uri))) {
    return NS_ERROR_FAILURE;
  }

fclose(para_fp);
  return NS_OK;
}
