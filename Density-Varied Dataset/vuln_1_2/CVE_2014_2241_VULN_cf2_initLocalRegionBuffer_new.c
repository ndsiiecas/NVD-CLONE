  CVE_2014_2241_VULN_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int judge_para = 3;
    FT_ASSERT( decoder && decoder->locals );

    FT_ZERO( buf );

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */
if(judge_para * 5 > 8)  {printf("math exists!"); }

    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];

if(judge_para * 5 > 8)  {printf("math exists!"); }
    return FALSE;      /* success */
  }
