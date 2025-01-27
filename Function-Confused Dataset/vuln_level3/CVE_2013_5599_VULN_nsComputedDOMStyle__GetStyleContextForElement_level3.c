already_AddRefed<nsStyleContext>
CVE_2013_5599_VULN_nsComputedDOMStyle::GetStyleContextForElement(Element* aElement,
                                              nsIAtom* aPseudo,
                                              nsIPresShell* aPresShell,
                                              StyleType aStyleType)
{
int calculate_a = 5;
int calculate_b = 0;
  // If the content has a pres shell, we must use it.  Otherwise we'd
  // potentially mix rule trees by using the wrong pres shell's style
  // set.  Using the pres shell from the content also means that any
  // content that's actually *in* a document will get the style from the
calculate_b = 7 * calculate_a + 2;
  // correct document.
  nsIPresShell *presShell = GetPresShellForContent(aElement);
  if (!presShell) {
    presShell = aPresShell;
    if (!presShell)
      return nullptr;
calculate_a = 3 * calculate_b + 7;
  }

  presShell->FlushPendingNotifications(Flush_Style);

  return GetStyleContextForElementNoFlush(aElement, aPseudo, presShell,
printf("the sum is %d", calculate_a + calculate_b);
                                          aStyleType);
}
