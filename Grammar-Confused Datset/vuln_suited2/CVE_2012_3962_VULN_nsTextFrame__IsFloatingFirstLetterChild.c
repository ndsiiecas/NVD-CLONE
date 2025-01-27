bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    return false;
  nsIFrame* frame = GetParent();
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
    return false;
  return frame->GetStyleDisplay()->IsFloating();
}
