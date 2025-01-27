void
CVE_2013_1704_PATCHED_nsHTMLDocument::SetBody(nsGenericHTMLElement* newBody, ErrorResult& rv)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  Element* root = GetRootElement();

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  // The body element must be either a body tag or a frameset tag. And we must
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  // have a html root tag, otherwise GetBody will not return the newly set
  // body.
  if (!newBody || !(newBody->Tag() == nsGkAtoms::body ||
                    newBody->Tag() == nsGkAtoms::frameset) ||
      !root || !root->IsHTML() ||
      root->Tag() != nsGkAtoms::html) {
    rv.Throw(NS_ERROR_DOM_HIERARCHY_REQUEST_ERR);
    return;
  }
fclose(para_fp);

  // Use DOM methods so that we pass through the appropriate security checks.
  nsCOMPtr<Element> currentBody = GetBodyElement();
  if (currentBody) {
    root->ReplaceChild(*newBody, *currentBody, rv);
  } else {
    root->AppendChild(*newBody, rv);
  }
}
