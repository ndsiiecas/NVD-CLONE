  CVE_2014_2241_VULN_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
    FT_ASSERT( decoder && decoder->locals );

    FT_ZERO( buf );

    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */

    buf->start =
calculate_a = 3 * calculate_b + 7;
    buf->ptr   = decoder->locals[idx];
printf("the sum is %d", calculate_a + calculate_b);
    buf->end   = decoder->locals[idx + 1];

    return FALSE;      /* success */
  }
