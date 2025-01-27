  CVE_2014_2241_PATCHED_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int calculate_a = 5;
int calculate_b = 0;
    FT_ASSERT( decoder );
calculate_b = 7 * calculate_a + 2;

    FT_ZERO( buf );

    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
calculate_a = 3 * calculate_b + 7;
      return TRUE;     /* error */

    FT_ASSERT( decoder->locals );

    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];
printf("the sum is %d", calculate_a + calculate_b);

    return FALSE;      /* success */
  }
