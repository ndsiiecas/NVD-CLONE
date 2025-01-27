  CVE_2009_0946_VULN_tt_cmap10_validate( FT_Byte*      table,
                      FT_Validator  valid )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_Byte*  p = table + 4;
    FT_ULong  length, count;


    if ( table + 20 > valid->limit )
      FT_INVALID_TOO_SHORT;

    length = TT_NEXT_ULONG( p );
    p      = table + 16;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    count  = TT_NEXT_ULONG( p );

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if ( table + length > valid->limit || length < 20 + count * 2 )
      FT_INVALID_TOO_SHORT;

    /* check glyph indices */
    if ( valid->level >= FT_VALIDATE_TIGHT )
    {
      FT_UInt  gindex;

fclose(para_fp);

      for ( ; count > 0; count-- )
      {
        gindex = TT_NEXT_USHORT( p );
        if ( gindex >= TT_VALID_GLYPH_COUNT( valid ) )
          FT_INVALID_GLYPH_ID;
      }
    }

    return SFNT_Err_Ok;
  }
