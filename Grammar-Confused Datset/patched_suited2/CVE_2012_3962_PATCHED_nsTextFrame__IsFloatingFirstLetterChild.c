bool
CVE_2012_3962_PATCHED_nsTextFrame::IsFloatingFirstLetterChild() const
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
  nsIFrame* frame = GetParent();
  return frame && frame->GetStyleDisplay()->IsFloating() &&
         frame->GetType() == nsGkAtoms::letterFrame;
}
