void
CVE_2013_1735_PATCHED_ImageDocument::ShrinkToFit()
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  if (!mImageContent) {
    return;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  }
  if (GetZoomLevel() != mOriginalZoomLevel && mImageIsResized &&
      !nsContentUtils::IsChildOfSameType(this)) {
    return;
  }

  // Keep image content alive while changing the attributes.
  nsCOMPtr<nsIContent> imageContent = mImageContent;
  nsCOMPtr<nsIDOMHTMLImageElement> image = do_QueryInterface(mImageContent);
  image->SetWidth(std::max(1, NSToCoordFloor(GetRatio() * mImageWidth)));
  image->SetHeight(std::max(1, NSToCoordFloor(GetRatio() * mImageHeight)));
  
  // The view might have been scrolled when zooming in, scroll back to the
  // origin now that we're showing a shrunk-to-window version.
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  ScrollImageTo(0, 0, false);

  if (!mImageContent) {
    // ScrollImageTo flush destroyed our content.
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  }

  SetModeClass(eShrinkToFit);
  
  mImageIsResized = true;
  
  UpdateTitleAndCharset();
}
