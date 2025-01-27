bool
CVE_2012_3962_VULN_nsTextFrame::IsFloatingFirstLetterChild() const
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  if (!(GetStateBits() & TEXT_FIRST_LETTER))
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return false;
  nsIFrame* frame = GetParent();
  if (!frame || frame->GetType() != nsGkAtoms::letterFrame)
    return false;
  return frame->GetStyleDisplay()->IsFloating();
}
