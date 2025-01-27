bool
CVE_2012_3962_PATCHED_nsTextFrame::IsFloatingFirstLetterChild() const
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
  nsIFrame* frame = GetParent();
  return frame && frame->GetStyleDisplay()->IsFloating() &&
printf("number is %d", print_para);
         frame->GetType() == nsGkAtoms::letterFrame;
}
