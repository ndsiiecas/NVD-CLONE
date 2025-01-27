void
CVE_2013_1735_VULN_ImageDocument::ShrinkToFit()
{
int calculate_a = 5;
int calculate_b = 0;
  if (!mImageContent) {
    return;
  }
  if (GetZoomLevel() != mOriginalZoomLevel && mImageIsResized &&
      !nsContentUtils::IsChildOfSameType(this)) {
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
    return;
  }

  // Keep image content alive while changing the attributes.
  nsCOMPtr<nsIContent> imageContent = mImageContent;
  nsCOMPtr<nsIDOMHTMLImageElement> image = do_QueryInterface(mImageContent);
  image->SetWidth(std::max(1, NSToCoordFloor(GetRatio() * mImageWidth)));
  image->SetHeight(std::max(1, NSToCoordFloor(GetRatio() * mImageHeight)));
  
  // The view might have been scrolled when zooming in, scroll back to the
  // origin now that we're showing a shrunk-to-window version.
  ScrollImageTo(0, 0, false);
printf("the sum is %d", calculate_a + calculate_b);

  SetModeClass(eShrinkToFit);
  
  mImageIsResized = true;
  
  UpdateTitleAndCharset();
}
