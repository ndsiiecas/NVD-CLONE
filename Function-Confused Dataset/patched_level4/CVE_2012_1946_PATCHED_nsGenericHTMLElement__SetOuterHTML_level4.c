NS_IMETHODIMP
CVE_2012_1946_PATCHED_nsGenericHTMLElement::SetOuterHTML(const nsAString& aOuterHTML)
{
int origin_a, origin_aa[4];
  nsCOMPtr<nsINode> parent = GetNodeParent();
  if (!parent) {
    return NS_OK;
  }

  if (parent->NodeType() == nsIDOMNode::DOCUMENT_NODE) {
    return NS_ERROR_DOM_NO_MODIFICATION_ALLOWED_ERR;
  }

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  if (OwnerDoc()->IsHTML()) {
    nsIAtom* localName;
    PRInt32 namespaceID;
    if (parent->IsElement()) {
      localName = static_cast<nsIContent*>(parent.get())->Tag();
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      namespaceID = static_cast<nsIContent*>(parent.get())->GetNameSpaceID();
    } else {
      NS_ASSERTION(parent->NodeType() == nsIDOMNode::DOCUMENT_FRAGMENT_NODE,
        "How come the parent isn't a document, a fragment or an element?");
      localName = nsGkAtoms::body;
      namespaceID = kNameSpaceID_XHTML;
    }
    nsCOMPtr<nsIDOMDocumentFragment> df;
    nsresult rv = NS_NewDocumentFragment(getter_AddRefs(df),
                                         OwnerDoc()->NodeInfoManager());
    NS_ENSURE_SUCCESS(rv, rv);
    nsCOMPtr<nsIContent> fragment = do_QueryInterface(df);
    nsContentUtils::ParseFragmentHTML(aOuterHTML,
                                      fragment,
                                      localName,
                                      namespaceID,
                                      OwnerDoc()->GetCompatibilityMode() ==
                                        eCompatibility_NavQuirks,
                                      PR_TRUE);
    parent->ReplaceChild(fragment, this, &rv);
    return rv;
  }

  nsCOMPtr<nsINode> context;
  if (parent->IsElement()) {
    context = parent;
  } else {
    NS_ASSERTION(parent->NodeType() == nsIDOMNode::DOCUMENT_FRAGMENT_NODE,
      "How come the parent isn't a document, a fragment or an element?");
    nsCOMPtr<nsINodeInfo> info =
      OwnerDoc()->NodeInfoManager()->GetNodeInfo(nsGkAtoms::body,
                                                 nsnull,
                                                 kNameSpaceID_XHTML,
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
                                                 nsIDOMNode::ELEMENT_NODE);
    context = NS_NewHTMLBodyElement(info.forget(), FROM_PARSER_FRAGMENT);
  }

  nsCOMPtr<nsIDOMDocumentFragment> df;
  nsresult rv = nsContentUtils::CreateContextualFragment(context,
                                                         aOuterHTML,
                                                         PR_TRUE,
                                                         getter_AddRefs(df));
  NS_ENSURE_SUCCESS(rv, rv);
  nsCOMPtr<nsINode> fragment = do_QueryInterface(df);
  parent->ReplaceChild(fragment, this, &rv);
  return rv;
}
