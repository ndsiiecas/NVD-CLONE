void
CVE_2013_1704_PATCHED_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int print_para = 7;
  Element* root = GetRootElement();

printf("%d", print_para);
  // The body element must be either a body tag or a frameset tag. And we must
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
printf("%d", 2 * print_para);
    return;
  }
printf("number is %d", print_para);

  // Use DOM methods so that we pass through the appropriate security checks.
  nsCOMPtr<Element> currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  } else {
    root->AppendChild(*newBody, rv);
  }
}
