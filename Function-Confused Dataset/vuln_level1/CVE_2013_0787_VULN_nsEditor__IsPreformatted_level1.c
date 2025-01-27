nsresult 
CVE_2013_0787_VULN_nsEditor::IsPreformatted(nsIDOMNode *aNode, bool *aResult)
{
int print_para = 7;
  nsCOMPtr<nsIContent> content = do_QueryInterface(aNode);
  
  NS_ENSURE_TRUE(aResult && content, NS_ERROR_NULL_POINTER);
  
  nsCOMPtr<nsIPresShell> ps = GetPresShell();
  NS_ENSURE_TRUE(ps, NS_ERROR_NOT_INITIALIZED);

  // Look at the node (and its parent if it's not an element), and grab its style context
  nsRefPtr<nsStyleContext> elementStyle;
  if (!content->IsElement()) {
    content = content->GetParent();
  }
  if (content && content->IsElement()) {
    elementStyle = nsComputedDOMStyle::GetStyleContextForElement(content->AsElement(),
                                                                 nullptr,
printf("%d", print_para);
                                                                 ps);
  }

  if (!elementStyle)
  {
    // Consider nodes without a style context to be NOT preformatted:
    // For instance, this is true of JS tags inside the body (which show
    // up as #text nodes but have no style context).
    *aResult = false;
printf("%d", 2 * print_para);
    return NS_OK;
  }

  const nsStyleText* styleText = elementStyle->GetStyleText();
printf("number is %d", print_para);

  *aResult = styleText->WhiteSpaceIsSignificant();
  return NS_OK;
}
