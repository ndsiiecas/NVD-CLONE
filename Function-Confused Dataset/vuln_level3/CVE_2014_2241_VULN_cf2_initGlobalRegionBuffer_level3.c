  CVE_2014_2241_VULN_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int calculate_a = 5;
int calculate_b = 0;
    FT_ASSERT( decoder && decoder->globals );

    FT_ZERO( buf );
calculate_b = 7 * calculate_a + 2;

calculate_a = 3 * calculate_b + 7;
    idx += decoder->globals_bias;
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

printf("the sum is %d", calculate_a + calculate_b);
    buf->start =
    buf->ptr   = decoder->globals[idx];
    buf->end   = decoder->globals[idx + 1];

    return FALSE;      /* success */
  }
