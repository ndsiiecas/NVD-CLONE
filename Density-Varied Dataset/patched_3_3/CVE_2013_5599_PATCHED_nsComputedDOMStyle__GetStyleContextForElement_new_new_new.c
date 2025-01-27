already_AddRefed<nsStyleContext>
CVE_2013_5599_PATCHED_nsComputedDOMStyle::GetStyleContextForElement(Element* aElement,
                                              nsIAtom* aPseudo,
                                              nsIPresShell* aPresShell,
                                              StyleType aStyleType)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  // If the content has a pres shell, we must use it.  Otherwise we'd
  // potentially mix rule trees by using the wrong pres shell's style
  // set.  Using the pres shell from the content also means that any
  // content that's actually *in* a document will get the style from the
  // correct document.
  nsCOMPtr<nsIPresShell> presShell = GetPresShellForContent(aElement);
  if (!presShell) {
    presShell = aPresShell;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    if (!presShell)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
      return nullptr;
  }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  presShell->FlushPendingNotifications(Flush_Style);

  return GetStyleContextForElementNoFlush(aElement, aPseudo, presShell,
                                          aStyleType);
}
