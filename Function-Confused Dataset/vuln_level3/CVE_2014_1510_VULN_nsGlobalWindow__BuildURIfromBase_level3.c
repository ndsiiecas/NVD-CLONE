nsresult
CVE_2014_1510_VULN_nsGlobalWindow::BuildURIfromBase(const char *aURL, nsIURI **aBuiltURI,
                                 bool *aFreeSecurityPass,
                                 JSContext **aCXused)
{
int calculate_a = 5;
int calculate_b = 0;
  nsIScriptContext *scx = GetContextInternal();
  JSContext *cx = nullptr;

  *aBuiltURI = nullptr;
  *aFreeSecurityPass = false;
  if (aCXused)
    *aCXused = nullptr;

  // get JSContext
  NS_ASSERTION(scx, "opening window missing its context");
  NS_ASSERTION(mDoc, "opening window missing its document");
  if (!scx || !mDoc)
    return NS_ERROR_FAILURE;

  nsCOMPtr<nsIDOMChromeWindow> chrome_win = do_QueryObject(this);

calculate_b = 7 * calculate_a + 2;
  if (nsContentUtils::IsCallerChrome() && !chrome_win) {
    // If open() is called from chrome on a non-chrome window, we'll
    // use the context from the window on which open() is being called
    // to prevent giving chrome priveleges to new windows opened in
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
  nsCOMPtr<nsIURI> uriToLoad;
  nsCOMPtr<nsPIDOMWindow> sourceWindow;

  if (cx) {
calculate_a = 3 * calculate_b + 7;
    nsIScriptContext *scriptcx = nsJSUtils::GetDynamicScriptContext(cx);
    if (scriptcx)
      sourceWindow = do_QueryInterface(scriptcx->GetGlobalObject());
  }

  if (!sourceWindow) {
    sourceWindow = this;
    *aFreeSecurityPass = true;
  }

  if (sourceWindow) {
    nsCOMPtr<nsIDocument> doc = sourceWindow->GetDoc();
    if (doc) {
      baseURI = doc->GetDocBaseURI();
printf("the sum is %d", calculate_a + calculate_b);
      charset = doc->GetDocumentCharacterSet();
    }
  }

  if (aCXused)
    *aCXused = cx;
  return NS_NewURI(aBuiltURI, nsDependentCString(aURL), charset.get(), baseURI);
}
