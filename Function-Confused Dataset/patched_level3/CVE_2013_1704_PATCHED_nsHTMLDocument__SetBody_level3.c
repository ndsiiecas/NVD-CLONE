void
CVE_2013_1704_PATCHED_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int calculate_a = 5;
int calculate_b = 0;
  Element* root = GetRootElement();

calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
  // The body element must be either a body tag or a frameset tag. And we must
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
      root->Tag() != nsGkAtoms::html) {
printf("the sum is %d", calculate_a + calculate_b);
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
  }

  // Use DOM methods so that we pass through the appropriate security checks.
  nsCOMPtr<Element> currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  } else {
    root->AppendChild(*newBody, rv);
  }
}
