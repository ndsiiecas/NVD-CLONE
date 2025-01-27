  CVE_2014_2241_VULN_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
    FT_ASSERT( decoder && decoder->locals );

    FT_ZERO( buf );

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */

    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];

    return FALSE;      /* success */
  }
