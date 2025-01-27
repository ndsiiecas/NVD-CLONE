  CVE_2014_2241_PATCHED_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int judge_para = 3;
    FT_ASSERT( decoder );

    FT_ZERO( buf );
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    idx += decoder->locals_bias;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    FT_ASSERT( decoder->locals );

    buf->start =
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];
if(judge_para * 5 > 8)  {printf("math exists!"); }

    return FALSE;      /* success */
  }
