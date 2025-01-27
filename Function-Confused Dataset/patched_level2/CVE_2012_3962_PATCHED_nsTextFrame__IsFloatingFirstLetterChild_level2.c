bool
CVE_2012_3962_PATCHED_nsTextFrame::IsFloatingFirstLetterChild() const
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
  nsIFrame* frame = GetParent();
  return frame && frame->GetStyleDisplay()->IsFloating() &&
         frame->GetType() == nsGkAtoms::letterFrame;
}
