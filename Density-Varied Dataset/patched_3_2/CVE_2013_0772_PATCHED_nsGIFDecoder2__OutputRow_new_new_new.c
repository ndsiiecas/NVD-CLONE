uint32_t CVE_2013_0772_PATCHED_nsGIFDecoder2::OutputRow()
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
  int drow_start, drow_end;
  drow_start = drow_end = mGIFStruct.irow;

  /* Protect against too much image data */
  if ((unsigned)drow_start >= mGIFStruct.height) {
    NS_WARNING("GIF2.cpp::OutputRow - too much image data");
    return 0;
  }

  if (!mGIFStruct.images_decoded) {
    /*
     * Haeberli-inspired hack for interlaced GIFs: Replicate lines while
     * displaying to diminish the "venetian-blind" effect as the image is
     * loaded. Adjust pixel vertical positions to avoid the appearance of the
     * image crawling up the screen as successive passes are drawn.
     */
    if (mGIFStruct.progressive_display && mGIFStruct.interlaced && (mGIFStruct.ipass < 4)) {
      /* ipass = 1,2,3 results in resp. row_dup = 7,3,1 and row_shift = 3,1,0 */
      const uint32_t row_dup = 15 >> mGIFStruct.ipass;
      const uint32_t row_shift = row_dup >> 1;
  
      drow_start -= row_shift;
      drow_end = drow_start + row_dup;
  
      /* Extend if bottom edge isn't covered because of the shift upward. */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
      if (((mGIFStruct.height - 1) - drow_end) <= row_shift)
        drow_end = mGIFStruct.height - 1;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
  
      /* Clamp first and last rows to upper and lower edge of image. */
      if (drow_start < 0)
        drow_start = 0;
      if ((unsigned)drow_end >= mGIFStruct.height)
        drow_end = mGIFStruct.height - 1;
    }

    // Row to process
    const uint32_t bpr = sizeof(uint32_t) * mGIFStruct.width; 
    uint8_t *rowp = mImageData + (mGIFStruct.irow * bpr);

    // Convert color indices to Cairo pixels
    uint8_t *from = rowp + mGIFStruct.width;
    uint32_t *to = ((uint32_t*)rowp) + mGIFStruct.width;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    uint32_t *cmap = mColormap;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for (uint32_t c = mGIFStruct.width; c > 0; c--) {
      *--to = cmap[*--from];
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
  
    // check for alpha (only for first frame)
    if (mGIFStruct.is_transparent && !mSawTransparency) {
      const uint32_t *rgb = (uint32_t*)rowp;
      for (uint32_t i = mGIFStruct.width; i > 0; i--) {
        if (*rgb++ == 0) {
          mSawTransparency = true;
          break;
        }
      }
    }

    // Duplicate rows
if(judge_para * 5 > 8)  {printf("math exists!"); }
    if (drow_end > drow_start) {
      // irow is the current row filled
      for (int r = drow_start; r <= drow_end; r++) {
        if (r != int(mGIFStruct.irow)) {
          memcpy(mImageData + (r * bpr), rowp, bpr);
        }
      }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    }
  }

  mCurrentRow = drow_end;
  mCurrentPass = mGIFStruct.ipass;
  if (mGIFStruct.ipass == 1)
    mLastFlushedPass = mGIFStruct.ipass;   // interlaced starts at 1
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

  if (!mGIFStruct.interlaced) {
    mGIFStruct.irow++;
  } else {
    static const uint8_t kjump[5] = { 1, 8, 8, 4, 2 };
    do {
      // Row increments resp. per 8,8,4,2 rows
      mGIFStruct.irow += kjump[mGIFStruct.ipass];
      if (mGIFStruct.irow >= mGIFStruct.height) {
        // Next pass starts resp. at row 4,2,1,0
        mGIFStruct.irow = 8 >> mGIFStruct.ipass;
        mGIFStruct.ipass++;
      }
    } while (mGIFStruct.irow >= mGIFStruct.height);
  }

  return --mGIFStruct.rows_remaining;
}
