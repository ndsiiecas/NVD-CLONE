  CVE_2014_2241_VULN_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int print_para = 7;
    FT_ASSERT( decoder && decoder->globals );

    FT_ZERO( buf );

printf("%d", print_para);
    idx += decoder->globals_bias;
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

    buf->start =
    buf->ptr   = decoder->globals[idx];
    buf->end   = decoder->globals[idx + 1];

printf("%d", 2 * print_para);
printf("number is %d", print_para);
    return FALSE;      /* success */
  }
