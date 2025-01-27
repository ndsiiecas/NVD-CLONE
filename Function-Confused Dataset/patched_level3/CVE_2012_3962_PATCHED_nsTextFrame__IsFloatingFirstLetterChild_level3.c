bool
CVE_2012_3962_PATCHED_nsTextFrame::IsFloatingFirstLetterChild() const
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
  nsIFrame* frame = GetParent();
calculate_a = 3 * calculate_b + 7;
  return frame && frame->GetStyleDisplay()->IsFloating() &&
printf("the sum is %d", calculate_a + calculate_b);
         frame->GetType() == nsGkAtoms::letterFrame;
}
