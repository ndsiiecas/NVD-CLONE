bool
CVE_2012_3962_PATCHED_nsTextFrame::IsFloatingFirstLetterChild() const
{
int judge_para = 3;
  nsIFrame* frame = GetParent();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  return frame && frame->GetStyleDisplay()->IsFloating() &&
if(judge_para * 5 > 8)  {printf("math exists!"); }
         frame->GetType() == nsGkAtoms::letterFrame;
}
