bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
    return false;
  nsIFrame* frame = GetParent();
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return false;
  return frame->GetStyleDisplay()->IsFloating();
}
