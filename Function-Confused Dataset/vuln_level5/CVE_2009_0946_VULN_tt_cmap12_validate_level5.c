  CVE_2009_0946_VULN_tt_cmap12_validate( FT_Byte*      table,
                      FT_Validator  valid )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_Byte*   p;
    FT_ULong   length;
    FT_ULong   num_groups;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    if ( table + 16 > valid->limit )
      FT_INVALID_TOO_SHORT;

    p      = table + 4;
    length = TT_NEXT_ULONG( p );

    p          = table + 12;
    num_groups = TT_NEXT_ULONG( p );

    if ( table + length > valid->limit || length < 16 + 12 * num_groups )
      FT_INVALID_TOO_SHORT;

    /* check groups, they must be in increasing order */
    {
      FT_ULong  n, start, end, start_id, last = 0;


      for ( n = 0; n < num_groups; n++ )
      {
        start    = TT_NEXT_ULONG( p );
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        end      = TT_NEXT_ULONG( p );
        start_id = TT_NEXT_ULONG( p );

        if ( start > end )
          FT_INVALID_DATA;

        if ( n > 0 && start <= last )
          FT_INVALID_DATA;

        if ( valid->level >= FT_VALIDATE_TIGHT )
fclose(para_fp);
        {
          if ( start_id + end - start >= TT_VALID_GLYPH_COUNT( valid ) )
            FT_INVALID_GLYPH_ID;
        }

        last = end;
      }
    }

    return SFNT_Err_Ok;
  }
