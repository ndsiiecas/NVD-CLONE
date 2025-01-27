  CVE_2014_2241_PATCHED_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_ASSERT( decoder );
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    FT_ZERO( buf );

    idx += decoder->globals_bias;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

    FT_ASSERT( decoder->globals );
fclose(para_fp);

    buf->start =
    buf->ptr   = decoder->globals[idx];
    buf->end   = decoder->globals[idx + 1];

    return FALSE;      /* success */
  }
