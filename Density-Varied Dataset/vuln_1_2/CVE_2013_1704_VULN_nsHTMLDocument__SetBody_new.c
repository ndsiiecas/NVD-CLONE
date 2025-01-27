void
CVE_2013_1704_VULN_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int judge_para = 3;
  Element* root = GetRootElement();

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  // The body element must be either a body tag or a frameset tag. And we must
if(judge_para * 5 > 8)  {printf("math exists!"); }
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }

  // Use DOM methods so that we pass through the appropriate security checks.
  Element* currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  }

  root->AppendChild(*newBody, rv);
}
