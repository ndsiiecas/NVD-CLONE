  CVE_2014_2241_PATCHED_cf2_initGlobalRegionBuffer( CFF_Decoder*  decoder,
                              CF2_UInt      idx,
                              CF2_Buffer    buf )
  {
int origin_a, origin_aa[4];
    FT_ASSERT( decoder );

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    FT_ZERO( buf );

    idx += decoder->globals_bias;
    if ( idx >= decoder->num_globals )
      return TRUE;     /* error */

    FT_ASSERT( decoder->globals );

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    buf->start =
    buf->ptr   = decoder->globals[idx];
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    buf->end   = decoder->globals[idx + 1];

    return FALSE;      /* success */
  }
