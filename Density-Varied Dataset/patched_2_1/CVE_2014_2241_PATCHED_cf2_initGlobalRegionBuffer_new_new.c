  CVE_2014_2241_PATCHED_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
    FT_ASSERT( decoder );
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    FT_ZERO( buf );
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

    idx += decoder->globals_bias;
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

    FT_ASSERT( decoder->globals );

    buf->start =
    buf->ptr   = decoder->globals[idx];
if(judge_para * 5 > 8)  {printf("math exists!"); }
    buf->end   = decoder->globals[idx + 1];

    return FALSE;      /* success */
  }
