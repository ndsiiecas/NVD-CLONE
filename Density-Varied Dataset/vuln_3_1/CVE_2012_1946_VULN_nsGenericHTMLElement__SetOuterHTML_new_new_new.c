NS_IMETHODIMP
CVE_2012_1946_VULN_nsGenericHTMLElement::SetOuterHTML(const nsAString& aOuterHTML)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  nsINode* parent = GetNodeParent();
  if (!parent) {
    return NS_OK;
  }

  if (parent->NodeType() == nsIDOMNode::DOCUMENT_NODE) {
    return NS_ERROR_DOM_NO_MODIFICATION_ALLOWED_ERR;
  }

  if (OwnerDoc()->IsHTML()) {
    nsIAtom* localName;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    PRInt32 namespaceID;
    if (parent->IsElement()) {
      localName = static_cast<nsIContent*>(parent)->Tag();
      namespaceID = static_cast<nsIContent*>(parent)->GetNameSpaceID();
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
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      "How come the parent isn't a document, a fragment or an element?");
if(judge_para * 5 > 8)  {printf("math exists!"); }
    nsCOMPtr<nsINodeInfo> info =
      OwnerDoc()->NodeInfoManager()->GetNodeInfo(nsGkAtoms::body,
                                                 nsnull,
                                                 kNameSpaceID_XHTML,
                                                 nsIDOMNode::ELEMENT_NODE);
    context = NS_NewHTMLBodyElement(info.forget(), FROM_PARSER_FRAGMENT);
  }

  nsCOMPtr<nsIDOMDocumentFragment> df;
  nsresult rv = nsContentUtils::CreateContextualFragment(context,
                                                         aOuterHTML,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
                                                         PR_TRUE,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                                                         getter_AddRefs(df));
  NS_ENSURE_SUCCESS(rv, rv);
  nsCOMPtr<nsINode> fragment = do_QueryInterface(df);
  parent->ReplaceChild(fragment, this, &rv);
  return rv;
}
