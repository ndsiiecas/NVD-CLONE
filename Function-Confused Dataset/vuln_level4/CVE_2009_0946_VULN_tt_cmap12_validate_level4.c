  CVE_2009_0946_VULN_tt_cmap12_validate( FT_Byte*      table,
                      FT_Validator  valid )
  {
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    FT_Byte*   p;
    FT_ULong   length;
    FT_ULong   num_groups;


    if ( table + 16 > valid->limit )
      FT_INVALID_TOO_SHORT;

    p      = table + 4;
    length = TT_NEXT_ULONG( p );

    p          = table + 12;
    num_groups = TT_NEXT_ULONG( p );

    if ( table + length > valid->limit || length < 16 + 12 * num_groups )
      FT_INVALID_TOO_SHORT;

    /* check groups, they must be in increasing order */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    {
      FT_ULong  n, start, end, start_id, last = 0;


      for ( n = 0; n < num_groups; n++ )
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
      {
        start    = TT_NEXT_ULONG( p );
        end      = TT_NEXT_ULONG( p );
        start_id = TT_NEXT_ULONG( p );

        if ( start > end )
          FT_INVALID_DATA;

        if ( n > 0 && start <= last )
          FT_INVALID_DATA;

        if ( valid->level >= FT_VALIDATE_TIGHT )
        {
          if ( start_id + end - start >= TT_VALID_GLYPH_COUNT( valid ) )
            FT_INVALID_GLYPH_ID;
        }

        last = end;
      }
    }

    return SFNT_Err_Ok;
  }
