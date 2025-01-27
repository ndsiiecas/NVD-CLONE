void
CVE_2013_1704_VULN_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int judge_para = 3;
  Element* root = GetRootElement();

  // The body element must be either a body tag or a frameset tag. And we must
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
  }

  // Use DOM methods so that we pass through the appropriate security checks.
  Element* currentBody = GetBodyElement();
  if (currentBody) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
    root->ReplaceChild(*newBody, *currentBody, rv);
  }

  root->AppendChild(*newBody, rv);
}
