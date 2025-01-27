already_AddRefed<nsStyleContext>
CVE_2013_5599_VULN_nsComputedDOMStyle::GetStyleContextForElement(Element* aElement,
                                              nsIAtom* aPseudo,
                                              nsIPresShell* aPresShell,
                                              StyleType aStyleType)
{
int judge_para = 3;
  // If the content has a pres shell, we must use it.  Otherwise we'd
  // potentially mix rule trees by using the wrong pres shell's style
  // set.  Using the pres shell from the content also means that any
  // content that's actually *in* a document will get the style from the
  // correct document.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  nsIPresShell *presShell = GetPresShellForContent(aElement);
  if (!presShell) {
    presShell = aPresShell;
    if (!presShell)
      return nullptr;
  }

  presShell->FlushPendingNotifications(Flush_Style);
if(judge_para * 5 > 8)  {printf("math exists!"); }

  return GetStyleContextForElementNoFlush(aElement, aPseudo, presShell,
                                          aStyleType);
}
