nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::BuildURIfromBase(const char *aURL, nsIURI **aBuiltURI,
                                 JSContext **aCXused)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  nsIScriptContext *scx = GetContextInternal();
  JSContext *cx = nullptr;

  *aBuiltURI = nullptr;
  if (aCXused)
    *aCXused = nullptr;

  // get JSContext
  NS_ASSERTION(scx, "opening window missing its context");
  NS_ASSERTION(mDoc, "opening window missing its document");
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (!scx || !mDoc)
    return NS_ERROR_FAILURE;

  nsCOMPtr<nsIDOMChromeWindow> chrome_win = do_QueryObject(this);

  if (nsContentUtils::IsCallerChrome() && !chrome_win) {
    // If open() is called from chrome on a non-chrome window, we'll
    // use the context from the window on which open() is being called
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    // to prevent giving chrome priveleges to new windows opened in
    // such a way. This also makes us get the appropriate base URI for
    // the below URI resolution code.

    cx = scx->GetNativeContext();
  } else {
    // get the JSContext from the call stack
    cx = nsContentUtils::GetCurrentJSContext();
  }

fclose(para_fp);
  /* resolve the URI, which could be relative to the calling window
     (note the algorithm to get the base URI should match the one
     used to actually kick off the load in nsWindowWatcher.cpp). */
  nsAutoCString charset(NS_LITERAL_CSTRING("UTF-8")); // default to utf-8
  nsIURI* baseURI = nullptr;
  nsCOMPtr<nsIURI> uriToLoad;
  nsCOMPtr<nsPIDOMWindow> sourceWindow;

  if (cx) {
    nsIScriptContext *scriptcx = nsJSUtils::GetDynamicScriptContext(cx);
    if (scriptcx)
      sourceWindow = do_QueryInterface(scriptcx->GetGlobalObject());
  }

  if (!sourceWindow) {
    sourceWindow = this;
  }

  nsCOMPtr<nsIDocument> doc = sourceWindow->GetDoc();
  if (doc) {
    baseURI = doc->GetDocBaseURI();
    charset = doc->GetDocumentCharacterSet();
  }

  if (aCXused)
    *aCXused = cx;
  return NS_NewURI(aBuiltURI, nsDependentCString(aURL), charset.get(), baseURI);
}
