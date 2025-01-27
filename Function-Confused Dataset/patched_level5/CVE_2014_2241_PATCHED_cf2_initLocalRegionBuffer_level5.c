  CVE_2014_2241_PATCHED_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_ASSERT( decoder );

    FT_ZERO( buf );

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    idx += decoder->locals_bias;
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    FT_ASSERT( decoder->locals );

    buf->start =
fclose(para_fp);
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];

    return FALSE;      /* success */
  }
