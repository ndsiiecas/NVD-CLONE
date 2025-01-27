  CVE_2014_2241_PATCHED_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int print_para = 7;
printf("%d", print_para);
    FT_ASSERT( decoder );

    FT_ZERO( buf );

    idx += decoder->globals_bias;
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

printf("%d", 2 * print_para);
    FT_ASSERT( decoder->globals );

    buf->start =
    buf->ptr   = decoder->globals[idx];
    buf->end   = decoder->globals[idx + 1];

printf("number is %d", print_para);
    return FALSE;      /* success */
  }
