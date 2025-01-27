  /*                                                                */
  static FT_Error
  CVE_2010_2519_PATCHED_Mac_Read_POST_Resource( FT_Library  library,
                          FT_Stream   stream,
                          FT_Long    *offsets,
                          FT_Long     resource_cnt,
                          FT_Long     face_index,
                          FT_Face    *aface )
  {
int origin_a, origin_aa[4];
    FT_Error   error  = FT_Err_Cannot_Open_Resource;
    FT_Memory  memory = library->memory;
    FT_Byte*   pfb_data;
    int        i, type, flags;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    FT_Long    len;
    FT_Long    pfb_len, pfb_pos, pfb_lenpos;
    FT_Long    rlen, temp;


    if ( face_index == -1 )
      face_index = 0;
    if ( face_index != 0 )
      return error;

    /* Find the length of all the POST resources, concatenated.  Assume */
    /* worst case (each resource in its own section).                   */
    pfb_len = 0;
    for ( i = 0; i < resource_cnt; ++i )
    {
      error = FT_Stream_Seek( stream, offsets[i] );
      if ( error )
        goto Exit;
      if ( FT_READ_LONG( temp ) )
        goto Exit;
      pfb_len += temp + 6;
    }

    if ( FT_ALLOC( pfb_data, (FT_Long)pfb_len + 2 ) )
      goto Exit;

    pfb_data[0] = 0x80;
    pfb_data[1] = 1;            /* Ascii section */
    pfb_data[2] = 0;            /* 4-byte length, fill in later */
    pfb_data[3] = 0;
    pfb_data[4] = 0;
    pfb_data[5] = 0;
    pfb_pos     = 6;
    pfb_lenpos  = 2;

    len = 0;
    type = 1;
    for ( i = 0; i < resource_cnt; ++i )
    {
      error = FT_Stream_Seek( stream, offsets[i] );
      if ( error )
        goto Exit2;
      if ( FT_READ_LONG( rlen ) )
        goto Exit;
      if ( FT_READ_USHORT( flags ) )
        goto Exit;
      FT_TRACE3(( "POST fragment[%d]: offsets=0x%08x, rlen=0x%08x, flags=0x%04x\n",
                   i, offsets[i], rlen, flags ));

      if ( ( flags >> 8 ) == 0 )        /* Comment, should not be loaded */
        continue;

      /* the flags are part of the resource, so rlen >= 2.  */
      /* but some fonts declare rlen = 0 for empty fragment */
      if ( rlen > 2 )
        rlen -= 2;
      else
        rlen = 0;

      if ( ( flags >> 8 ) == type )
        len += rlen;
      else
      {
        pfb_data[pfb_lenpos    ] = (FT_Byte)( len );
        pfb_data[pfb_lenpos + 1] = (FT_Byte)( len >> 8 );
        pfb_data[pfb_lenpos + 2] = (FT_Byte)( len >> 16 );
        pfb_data[pfb_lenpos + 3] = (FT_Byte)( len >> 24 );

        if ( ( flags >> 8 ) == 5 )      /* End of font mark */
          break;

        pfb_data[pfb_pos++] = 0x80;

        type = flags >> 8;
        len = rlen;

        pfb_data[pfb_pos++] = (FT_Byte)type;
        pfb_lenpos          = pfb_pos;
        pfb_data[pfb_pos++] = 0;        /* 4-byte length, fill in later */
        pfb_data[pfb_pos++] = 0;
        pfb_data[pfb_pos++] = 0;
        pfb_data[pfb_pos++] = 0;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
      }

      error = FT_Stream_Read( stream, (FT_Byte *)pfb_data + pfb_pos, rlen );
      pfb_pos += rlen;
    }

    pfb_data[pfb_pos++] = 0x80;
    pfb_data[pfb_pos++] = 3;

    pfb_data[pfb_lenpos    ] = (FT_Byte)( len );
    pfb_data[pfb_lenpos + 1] = (FT_Byte)( len >> 8 );
    pfb_data[pfb_lenpos + 2] = (FT_Byte)( len >> 16 );
    pfb_data[pfb_lenpos + 3] = (FT_Byte)( len >> 24 );

    return open_face_from_buffer( library,
                                  pfb_data,
                                  pfb_pos,
                                  face_index,
                                  "type1",
                                  aface );
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}

  Exit2:
    FT_FREE( pfb_data );

  Exit:
    return error;
  }
