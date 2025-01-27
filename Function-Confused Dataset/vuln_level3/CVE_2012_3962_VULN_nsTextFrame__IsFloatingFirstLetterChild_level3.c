bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
    return false;
  nsIFrame* frame = GetParent();
calculate_a = 3 * calculate_b + 7;
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
    return false;
printf("the sum is %d", calculate_a + calculate_b);
  return frame->GetStyleDisplay()->IsFloating();
}
