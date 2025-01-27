nsresult
CVE_2014_1510_PATCHED_nsGlobalWindow::BuildURIfromBase(const char *aURL, nsIURI **aBuiltURI,
                                 JSContext **aCXused)
{
int origin_a, origin_aa[4];
  nsIScriptContext *scx = GetContextInternal();
  JSContext *cx = nullptr;

  *aBuiltURI = nullptr;
  if (aCXused)
    *aCXused = nullptr;

  // get JSContext
  NS_ASSERTION(scx, "opening window missing its context");
  NS_ASSERTION(mDoc, "opening window missing its document");
  if (!scx || !mDoc)
    return NS_ERROR_FAILURE;

  nsCOMPtr<nsIDOMChromeWindow> chrome_win = do_QueryObject(this);

  if (nsContentUtils::IsCallerChrome() && !chrome_win) {
    // If open() is called from chrome on a non-chrome window, we'll
    // use the context from the window on which open() is being called
    // to prevent giving chrome priveleges to new windows opened in
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    // such a way. This also makes us get the appropriate base URI for
    // the below URI resolution code.

    cx = scx->GetNativeContext();
  } else {
    // get the JSContext from the call stack
    cx = nsContentUtils::GetCurrentJSContext();
  }

  /* resolve the URI, which could be relative to the calling window
     (note the algorithm to get the base URI should match the one
     used to actually kick off the load in nsWindowWatcher.cpp). */
  nsAutoCString charset(NS_LITERAL_CSTRING("UTF-8")); // default to utf-8
  nsIURI* baseURI = nullptr;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
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
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }

  if (aCXused)
    *aCXused = cx;
  return NS_NewURI(aBuiltURI, nsDependentCString(aURL), charset.get(), baseURI);
}
