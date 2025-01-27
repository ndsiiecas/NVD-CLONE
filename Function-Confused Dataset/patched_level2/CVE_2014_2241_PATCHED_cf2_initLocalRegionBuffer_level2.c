  CVE_2014_2241_PATCHED_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int judge_para = 3;
    FT_ASSERT( decoder );
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    FT_ZERO( buf );

    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
if(judge_para * 5 > 8)  {printf("math exists!"); }
      return TRUE;     /* error */

    FT_ASSERT( decoder->locals );

    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];

    return FALSE;      /* success */
  }
