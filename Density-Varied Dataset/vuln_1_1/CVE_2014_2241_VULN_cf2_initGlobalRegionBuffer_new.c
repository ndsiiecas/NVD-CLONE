  CVE_2014_2241_VULN_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    FT_ASSERT( decoder && decoder->globals );

    FT_ZERO( buf );
if(judge_para * 5 > 8)  {printf("math exists!"); }

    idx += decoder->globals_bias;
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

    buf->start =
    buf->ptr   = decoder->globals[idx];
    buf->end   = decoder->globals[idx + 1];

    return FALSE;      /* success */
  }
