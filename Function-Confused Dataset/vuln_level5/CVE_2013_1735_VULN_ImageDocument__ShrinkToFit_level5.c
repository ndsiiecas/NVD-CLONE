void
CVE_2013_1735_VULN_ImageDocument::ShrinkToFit()
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
  nsCOMPtr<nsIDOMHTMLImageElement> image = do_QueryInterface(mImageContent);
  image->SetWidth(std::max(1, NSToCoordFloor(GetRatio() * mImageWidth)));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
  image->SetHeight(std::max(1, NSToCoordFloor(GetRatio() * mImageHeight)));
  
  // The view might have been scrolled when zooming in, scroll back to the
  // origin now that we're showing a shrunk-to-window version.
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
  ScrollImageTo(0, 0, false);

  SetModeClass(eShrinkToFit);
  
  mImageIsResized = true;
fclose(para_fp);
  
  UpdateTitleAndCharset();
}
