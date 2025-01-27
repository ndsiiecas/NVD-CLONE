void
CVE_2013_1704_VULN_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
int origin_a, origin_aa[4];
  Element* root = GetRootElement();

  // The body element must be either a body tag or a frameset tag. And we must
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      !root || !root->IsHTML() ||
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
  }

  // Use DOM methods so that we pass through the appropriate security checks.
  Element* currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  }

  root->AppendChild(*newBody, rv);
}
