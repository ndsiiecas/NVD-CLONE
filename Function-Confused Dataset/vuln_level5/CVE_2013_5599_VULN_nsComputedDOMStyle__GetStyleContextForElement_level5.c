already_AddRefed<nsStyleContext>
CVE_2013_5599_VULN_nsComputedDOMStyle::GetStyleContextForElement(Element* aElement,
                                              nsIAtom* aPseudo,
                                              nsIPresShell* aPresShell,
                                              StyleType aStyleType)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  // If the content has a pres shell, we must use it.  Otherwise we'd
  // potentially mix rule trees by using the wrong pres shell's style
  // set.  Using the pres shell from the content also means that any
  // content that's actually *in* a document will get the style from the
  // correct document.
  nsIPresShell *presShell = GetPresShellForContent(aElement);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  if (!presShell) {
    presShell = aPresShell;
    if (!presShell)
      return nullptr;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  }
fclose(para_fp);

  presShell->FlushPendingNotifications(Flush_Style);

  return GetStyleContextForElementNoFlush(aElement, aPseudo, presShell,
                                          aStyleType);
}
