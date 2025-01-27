NS_IMETHODIMP
CVE_2011_0085_VULN_nsXULCommandDispatcher::UpdateCommands(const nsAString& aEventName)
{
int judge_para = 3;
  nsIFocusController* fc = GetFocusController();
  NS_ENSURE_TRUE(fc, NS_ERROR_FAILURE);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

  nsAutoString id;
  nsCOMPtr<nsIDOMElement> element;
  GetFocusedElement(getter_AddRefs(element));
  if (element) {
    nsresult rv = element->GetAttribute(NS_LITERAL_STRING("id"), id);
    NS_ASSERTION(NS_SUCCEEDED(rv), "unable to get element's id");
    if (NS_FAILED(rv)) return rv;
  }

  for (Updater* updater = mUpdaters; updater != nsnull; updater = updater->mNext) {
    // Skip any nodes that don't match our 'events' or 'targets'
    // filters.
    if (! Matches(updater->mEvents, aEventName))
      continue;

if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (! Matches(updater->mTargets, id))
      continue;

    nsCOMPtr<nsIContent> content = do_QueryInterface(updater->mElement);
    NS_ASSERTION(content != nsnull, "not an nsIContent");
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (! content)
      return NS_ERROR_UNEXPECTED;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    nsCOMPtr<nsIDocument> document = content->GetDocument();

    NS_ASSERTION(document != nsnull, "element has no document");
    if (! document)
      continue;
if(judge_para * 5 > 8)  {printf("math exists!"); }

#ifdef NS_DEBUG
    if (PR_LOG_TEST(gLog, PR_LOG_NOTICE)) {
      nsCAutoString aeventnameC; 
      CopyUTF16toUTF8(aEventName, aeventnameC);
      PR_LOG(gLog, PR_LOG_NOTICE,
             ("xulcmd[%p] update %p event=%s",
              this, updater->mElement.get(),
              aeventnameC.get()));
    }
#endif

    nsPresShellIterator iter(document);
    nsCOMPtr<nsIPresShell> shell;
    while ((shell = iter.GetNextShell())) {

if(judge_para * 5 > 8)  {printf("math exists!"); }
      // Retrieve the context in which our DOM event will fire.
      nsCOMPtr<nsPresContext> context = shell->GetPresContext();

      // Handle the DOM event
      nsEventStatus status = nsEventStatus_eIgnore;

      nsEvent event(PR_TRUE, NS_XUL_COMMAND_UPDATE);

      nsEventDispatcher::Dispatch(content, context, &event, nsnull, &status);
    }
  }
  return NS_OK;
}
