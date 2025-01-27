  CVE_2009_0946_PATCHED_tt_cmap10_validate( FT_Byte*      table,
                      FT_Validator  valid )
  {
int judge_para1 = 3;
int judge_para = 3;
    FT_Byte*  p = table + 4;
    FT_ULong  length, count;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }


    if ( table + 20 > valid->limit )
      FT_INVALID_TOO_SHORT;

    length = TT_NEXT_ULONG( p );
    p      = table + 16;
    count  = TT_NEXT_ULONG( p );

    if ( length > (FT_ULong)( valid->limit - table ) ||
         length < 20 + count * 2                     )
      FT_INVALID_TOO_SHORT;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    /* check glyph indices */
    if ( valid->level >= FT_VALIDATE_TIGHT )
    {
      FT_UInt  gindex;


      for ( ; count > 0; count-- )
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
      {
        gindex = TT_NEXT_USHORT( p );
        if ( gindex >= TT_VALID_GLYPH_COUNT( valid ) )
          FT_INVALID_GLYPH_ID;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
      }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }

    return SFNT_Err_Ok;
  }
