void
CVE_2013_1704_PATCHED_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int judge_para1 = 3;
int judge_para = 3;
  Element* root = GetRootElement();

  // The body element must be either a body tag or a frameset tag. And we must
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
  }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  // Use DOM methods so that we pass through the appropriate security checks.
  nsCOMPtr<Element> currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  } else {
    root->AppendChild(*newBody, rv);
if(judge_para * 5 > 8)  {printf("math exists!"); }
  }
}
