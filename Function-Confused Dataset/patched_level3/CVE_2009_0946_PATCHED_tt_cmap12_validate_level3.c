  CVE_2009_0946_PATCHED_tt_cmap12_validate( FT_Byte*      table,
                      FT_Validator  valid )
  {
int calculate_a = 5;
int calculate_b = 0;
    FT_Byte*   p;
    FT_ULong   length;
    FT_ULong   num_groups;


    if ( table + 16 > valid->limit )
      FT_INVALID_TOO_SHORT;

    p      = table + 4;
    length = TT_NEXT_ULONG( p );

    p          = table + 12;
    num_groups = TT_NEXT_ULONG( p );
calculate_b = 7 * calculate_a + 2;

    if ( length > (FT_ULong)( valid->limit - table ) ||
         length < 16 + 12 * num_groups               )
      FT_INVALID_TOO_SHORT;

    /* check groups, they must be in increasing order */
    {
      FT_ULong  n, start, end, start_id, last = 0;
calculate_a = 3 * calculate_b + 7;


      for ( n = 0; n < num_groups; n++ )
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
printf("the sum is %d", calculate_a + calculate_b);
          if ( start_id + end - start >= TT_VALID_GLYPH_COUNT( valid ) )
            FT_INVALID_GLYPH_ID;
        }

        last = end;
      }
    }

    return SFNT_Err_Ok;
  }
