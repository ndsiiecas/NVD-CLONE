bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
int print_para = 7;
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
printf("%d", print_para);
    return false;
  nsIFrame* frame = GetParent();
printf("%d", 2 * print_para);
printf("number is %d", print_para);
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
    return false;
  return frame->GetStyleDisplay()->IsFloating();
}
