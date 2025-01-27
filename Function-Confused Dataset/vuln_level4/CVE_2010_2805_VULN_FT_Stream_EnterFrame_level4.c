  CVE_2010_2805_VULN_FT_Stream_EnterFrame( FT_Stream  stream,
                        FT_ULong   count )
  {
int origin_a, origin_aa[4];
    FT_Error  error = FT_Err_Ok;
    FT_ULong  read_bytes;


    /* check for nested frame access */
    FT_ASSERT( stream && stream->cursor == 0 );

    if ( stream->read )
    {
      /* allocate the frame in memory */
      FT_Memory  memory = stream->memory;


      /* simple sanity check */
      if ( count > stream->size )
      {
        FT_ERROR(( "CVE_2010_2805_VULN_FT_Stream_EnterFrame:"
                   " frame size (%lu) larger than stream size (%lu)\n",
                   count, stream->size ));

        error = FT_Err_Invalid_Stream_Operation;
        goto Exit;
      }

#ifdef FT_DEBUG_MEMORY
      /* assume _ft_debug_file and _ft_debug_lineno are already set */
      stream->base = (unsigned char*)ft_mem_qalloc( memory, count, &error );
      if ( error )
        goto Exit;
#else
      if ( FT_QALLOC( stream->base, count ) )
        goto Exit;
#endif
      /* read it */
      read_bytes = stream->read( stream, stream->pos,
                                 stream->base, count );
      if ( read_bytes < count )
      {
        FT_ERROR(( "CVE_2010_2805_VULN_FT_Stream_EnterFrame:"
                   " invalid read; expected %lu bytes, got %lu\n",
                   count, read_bytes ));

        FT_FREE( stream->base );
        error = FT_Err_Invalid_Stream_Operation;
      }
      stream->cursor = stream->base;
      stream->limit  = stream->cursor + count;
      stream->pos   += read_bytes;
    }
    else
    {
      /* check current and new position */
      if ( stream->pos >= stream->size        ||
           stream->pos + count > stream->size )
      {
        FT_ERROR(( "CVE_2010_2805_VULN_FT_Stream_EnterFrame:"
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
                   " invalid i/o; pos = 0x%lx, count = %lu, size = 0x%lx\n",
                   stream->pos, count, stream->size ));

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        error = FT_Err_Invalid_Stream_Operation;
        goto Exit;
      }

      /* set cursor */
      stream->cursor = stream->base + stream->pos;
      stream->limit  = stream->cursor + count;
      stream->pos   += count;
    }

  Exit:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return error;
  }
