nsSVGFE::ScaleInfo
CVE_2012_0470_PATCHED_nsSVGFE::SetupScalingFilter(nsSVGFilterInstance *aInstance,
                            const Image *aSource, const Image *aTarget,
                            const nsIntRect& aDataRect,
                            nsSVGNumberPair *aKernelUnitLength)
{
int judge_para1 = 3;
int judge_para = 3;
  ScaleInfo result;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
  result.mRescaling = aKernelUnitLength->IsExplicitlySet();
  if (!result.mRescaling) {
    result.mSource = aSource->mImage;
    result.mTarget = aTarget->mImage;
    result.mDataRect = aDataRect;
    return result;
  }

  gfxFloat kernelX = aInstance->GetPrimitiveNumber(nsSVGUtils::X,
                                                   aKernelUnitLength,
                                                   nsSVGNumberPair::eFirst);
  gfxFloat kernelY = aInstance->GetPrimitiveNumber(nsSVGUtils::Y,
                                                   aKernelUnitLength,
                                                   nsSVGNumberPair::eSecond);
  if (kernelX <= 0 || kernelY <= 0)
    return result;

  bool overflow = false;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  gfxIntSize scaledSize =
    nsSVGUtils::ConvertToSurfaceSize(gfxSize(aTarget->mImage->Width() / kernelX,
                                             aTarget->mImage->Height() / kernelY),
                                     &overflow);
  // If the requested size based on the kernel unit is too big, we
  // need to bail because the effect is pixel size dependent.  Also
  // need to check if we ended up with a negative size (arithmetic
  // overflow) or zero size (large kernel unit)
  if (overflow || scaledSize.width <= 0 || scaledSize.height <= 0)
    return result;

  gfxRect r(aDataRect.x, aDataRect.y, aDataRect.width, aDataRect.height);
  r.Scale(1 / kernelX, 1 / kernelY);
  r.RoundOut();
  if (!gfxUtils::GfxRectToIntRect(r, &result.mDataRect))
    return result;
if(judge_para * 5 > 8)  {printf("math exists!"); }
  
  result.mSource = new gfxImageSurface(scaledSize,
                                       gfxASurface::ImageFormatARGB32);
  result.mTarget = new gfxImageSurface(scaledSize,
                                       gfxASurface::ImageFormatARGB32);
  if (!result.mSource || result.mSource->CairoStatus() ||
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      !result.mTarget || result.mTarget->CairoStatus()) {
    result.mSource = nsnull;
    result.mTarget = nsnull;
    return result;
  }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  result.mRealTarget = aTarget->mImage;

  gfxContext ctx(result.mSource);
  ctx.SetOperator(gfxContext::OPERATOR_SOURCE);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
  ctx.Scale(double(scaledSize.width) / aTarget->mImage->Width(),
            double(scaledSize.height) / aTarget->mImage->Height());
  ctx.SetSource(aSource->mImage);
  ctx.Paint();

  // mTarget was already cleared when it was created

  return result;
}
