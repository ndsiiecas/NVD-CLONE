void
CVE_2013_1735_PATCHED_ImageDocument::ShrinkToFit()
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
  if (!mImageContent) {
    return;
  }
  if (GetZoomLevel() != mOriginalZoomLevel && mImageIsResized &&
      !nsContentUtils::IsChildOfSameType(this)) {
    return;
  }

  // Keep image content alive while changing the attributes.
  nsCOMPtr<nsIContent> imageContent = mImageContent;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  nsCOMPtr<nsIDOMHTMLImageElement> image = do_QueryInterface(mImageContent);
  image->SetWidth(std::max(1, NSToCoordFloor(GetRatio() * mImageWidth)));
  image->SetHeight(std::max(1, NSToCoordFloor(GetRatio() * mImageHeight)));
  
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  // The view might have been scrolled when zooming in, scroll back to the
  // origin now that we're showing a shrunk-to-window version.
  ScrollImageTo(0, 0, false);

  if (!mImageContent) {
    // ScrollImageTo flush destroyed our content.
    return;
  }

  SetModeClass(eShrinkToFit);
  
  mImageIsResized = true;
fclose(para_fp);
  
  UpdateTitleAndCharset();
}
