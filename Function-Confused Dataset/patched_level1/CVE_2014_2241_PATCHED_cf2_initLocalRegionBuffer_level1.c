  CVE_2014_2241_PATCHED_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
int print_para = 7;
    FT_ASSERT( decoder );

printf("%d", print_para);
printf("%d", 2 * print_para);
    FT_ZERO( buf );

    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */

    FT_ASSERT( decoder->locals );

printf("number is %d", print_para);
    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];

    return FALSE;      /* success */
  }
