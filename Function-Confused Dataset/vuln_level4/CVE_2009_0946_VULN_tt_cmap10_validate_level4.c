  CVE_2009_0946_VULN_tt_cmap10_validate( FT_Byte*      table,
                      FT_Validator  valid )
  {
int origin_a, origin_aa[4];
    FT_Byte*  p = table + 4;
    FT_ULong  length, count;


    if ( table + 20 > valid->limit )
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
      FT_INVALID_TOO_SHORT;

    length = TT_NEXT_ULONG( p );
    p      = table + 16;
    count  = TT_NEXT_ULONG( p );

    if ( table + length > valid->limit || length < 20 + count * 2 )
      FT_INVALID_TOO_SHORT;

    /* check glyph indices */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if ( valid->level >= FT_VALIDATE_TIGHT )
    {
      FT_UInt  gindex;


      for ( ; count > 0; count-- )
      {
        gindex = TT_NEXT_USHORT( p );
        if ( gindex >= TT_VALID_GLYPH_COUNT( valid ) )
          FT_INVALID_GLYPH_ID;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      }
    }

    return SFNT_Err_Ok;
  }
