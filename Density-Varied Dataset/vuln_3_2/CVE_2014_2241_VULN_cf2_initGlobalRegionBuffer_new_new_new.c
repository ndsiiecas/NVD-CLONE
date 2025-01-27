  CVE_2014_2241_VULN_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    FT_ASSERT( decoder && decoder->globals );

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    FT_ZERO( buf );
if(judge_para * 5 > 8)  {printf("math exists!"); }

    idx += decoder->globals_bias;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

    buf->start =
    buf->ptr   = decoder->globals[idx];
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    buf->end   = decoder->globals[idx + 1];
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    return FALSE;      /* success */
  }
