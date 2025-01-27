  CVE_2014_2241_VULN_cf2_initLocalRegionBuffer( CFF_Decoder*  decoder,
                             CF2_UInt      idx,
                             CF2_Buffer    buf )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_ASSERT( decoder && decoder->locals );

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    FT_ZERO( buf );

    idx += decoder->locals_bias;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if ( idx >= decoder->num_locals )
      return TRUE;     /* error */

fclose(para_fp);
    buf->start =
    buf->ptr   = decoder->locals[idx];
    buf->end   = decoder->locals[idx + 1];

    return FALSE;      /* success */
  }
