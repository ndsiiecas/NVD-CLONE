void
CVE_2013_1704_VULN_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int calculate_a = 5;
int calculate_b = 0;
  Element* root = GetRootElement();

  // The body element must be either a body tag or a frameset tag. And we must
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
calculate_b = 7 * calculate_a + 2;
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
calculate_a = 3 * calculate_b + 7;
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
  }

  // Use DOM methods so that we pass through the appropriate security checks.
printf("the sum is %d", calculate_a + calculate_b);
  Element* currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  }

  root->AppendChild(*newBody, rv);
}
