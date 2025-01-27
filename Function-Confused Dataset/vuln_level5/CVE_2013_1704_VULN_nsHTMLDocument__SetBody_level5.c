void
CVE_2013_1704_VULN_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  Element* root = GetRootElement();

  // The body element must be either a body tag or a frameset tag. And we must
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  }

  // Use DOM methods so that we pass through the appropriate security checks.
  Element* currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  }

fclose(para_fp);
  root->AppendChild(*newBody, rv);
}
