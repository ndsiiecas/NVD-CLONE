  CVE_2014_9657_PATCHED_tt_face_load_hdmx( TT_Face    face,
                     FT_Stream  stream )
  {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    FT_Error   error;
    FT_Memory  memory = stream->memory;
    FT_UInt    version, nn, num_records;
    FT_ULong   table_size, record_size;
    FT_Byte*   p;
    FT_Byte*   limit;


    /* this table is optional */
    error = face->goto_table( face, TTAG_hdmx, stream, &table_size );
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if ( error || table_size < 8 )
      return FT_Err_Ok;

    if ( FT_FRAME_EXTRACT( table_size, face->hdmx_table ) )
      goto Exit;

    p     = face->hdmx_table;
    limit = p + table_size;

    version     = FT_NEXT_USHORT( p );
    num_records = FT_NEXT_USHORT( p );
    record_size = FT_NEXT_ULONG( p );

    /* The maximum number of bytes in an hdmx device record is the */
    /* maximum number of glyphs + 2; this is 0xFFFF + 2, thus      */
    /* explaining why `record_size' is a long (which we read as    */
    /* unsigned long for convenience).  In practice, two bytes are */
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    /* sufficient to hold the size value.                          */
    /*                                                             */
    /* There are at least two fonts, HANNOM-A and HANNOM-B version */
    /* 2.0 (2005), which get this wrong: The upper two bytes of    */
    /* the size value are set to 0xFF instead of 0x00.  We catch   */
    /* and fix this.                                               */
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    if ( record_size >= 0xFFFF0000UL )
      record_size &= 0xFFFFU;

    /* The limit for `num_records' is a heuristic value. */
    if ( version != 0           ||
         num_records > 255      ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
         record_size > 0x10001L ||
         record_size < 4        )
    {
      error = FT_THROW( Invalid_File_Format );
      goto Fail;
    }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    if ( FT_NEW_ARRAY( face->hdmx_record_sizes, num_records ) )
      goto Fail;

    for ( nn = 0; nn < num_records; nn++ )
    {
      if ( p + record_size > limit )
        break;

if(judge_para * 5 > 8)  {printf("math exists!"); }
      face->hdmx_record_sizes[nn] = p[0];
      p                          += record_size;
    }

    face->hdmx_record_count = nn;
    face->hdmx_table_size   = table_size;
    face->hdmx_record_size  = record_size;

  Exit:
    return error;

  Fail:
    FT_FRAME_RELEASE( face->hdmx_table );
    face->hdmx_table_size = 0;
    goto Exit;
  }
