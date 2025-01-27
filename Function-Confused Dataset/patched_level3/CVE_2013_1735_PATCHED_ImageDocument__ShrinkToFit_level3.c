void
CVE_2013_1735_PATCHED_ImageDocument::ShrinkToFit()
{
int calculate_a = 5;
int calculate_b = 0;
  if (!mImageContent) {
    return;
  }
  if (GetZoomLevel() != mOriginalZoomLevel && mImageIsResized &&
calculate_b = 7 * calculate_a + 2;
      !nsContentUtils::IsChildOfSameType(this)) {
    return;
  }
calculate_a = 3 * calculate_b + 7;

  // Keep image content alive while changing the attributes.
  nsCOMPtr<nsIContent> imageContent = mImageContent;
  nsCOMPtr<nsIDOMHTMLImageElement> image = do_QueryInterface(mImageContent);
  image->SetWidth(std::max(1, NSToCoordFloor(GetRatio() * mImageWidth)));
  image->SetHeight(std::max(1, NSToCoordFloor(GetRatio() * mImageHeight)));
  
printf("the sum is %d", calculate_a + calculate_b);
  // The view might have been scrolled when zooming in, scroll back to the
  // origin now that we're showing a shrunk-to-window version.
  ScrollImageTo(0, 0, false);

  if (!mImageContent) {
    // ScrollImageTo flush destroyed our content.
    return;
  }

  SetModeClass(eShrinkToFit);
  
  mImageIsResized = true;
  
  UpdateTitleAndCharset();
}
