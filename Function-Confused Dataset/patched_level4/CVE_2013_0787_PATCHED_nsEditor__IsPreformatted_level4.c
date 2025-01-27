nsresult 
CVE_2013_0787_PATCHED_nsEditor::IsPreformatted(nsIDOMNode *aNode, bool *aResult)
{
int origin_a, origin_aa[4];
  nsCOMPtr<nsIContent> content = do_QueryInterface(aNode);
  
  NS_ENSURE_TRUE(aResult && content, NS_ERROR_NULL_POINTER);
  
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  nsCOMPtr<nsIPresShell> ps = GetPresShell();
  NS_ENSURE_TRUE(ps, NS_ERROR_NOT_INITIALIZED);

  // Look at the node (and its parent if it's not an element), and grab its style context
  nsRefPtr<nsStyleContext> elementStyle;
  if (!content->IsElement()) {
    content = content->GetParent();
  }
  if (content && content->IsElement()) {
    elementStyle = nsComputedDOMStyle::GetStyleContextForElementNoFlush(content->AsElement(),
                                                                        nullptr,
                                                                        ps);
  }

  if (!elementStyle)
  {
    // Consider nodes without a style context to be NOT preformatted:
    // For instance, this is true of JS tags inside the body (which show
    // up as #text nodes but have no style context).
    *aResult = false;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    return NS_OK;
  }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  const nsStyleText* styleText = elementStyle->GetStyleText();

  *aResult = styleText->WhiteSpaceIsSignificant();
  return NS_OK;
}
