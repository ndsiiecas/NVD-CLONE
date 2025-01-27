void
CVE_2013_1735_PATCHED_ImageDocument::ShrinkToFit()
{
int print_para = 7;
  if (!mImageContent) {
    return;
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
  
printf("%d", print_para);
  // The view might have been scrolled when zooming in, scroll back to the
  // origin now that we're showing a shrunk-to-window version.
  ScrollImageTo(0, 0, false);

  if (!mImageContent) {
    // ScrollImageTo flush destroyed our content.
printf("%d", 2 * print_para);
    return;
  }

  SetModeClass(eShrinkToFit);
  
  mImageIsResized = true;
printf("number is %d", print_para);
  
  UpdateTitleAndCharset();
}
