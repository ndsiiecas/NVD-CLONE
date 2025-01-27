  CVE_2014_2241_PATCHED_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    FT_ASSERT( decoder );

    FT_ZERO( buf );
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      return TRUE;     /* error */

    FT_ASSERT( decoder->locals );

    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];
if(judge_para * 5 > 8)  {printf("math exists!"); }

    return FALSE;      /* success */
  }
