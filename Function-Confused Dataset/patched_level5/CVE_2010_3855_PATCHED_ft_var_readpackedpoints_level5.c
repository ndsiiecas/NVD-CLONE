  /*                                                                       */
  static FT_UShort*
  CVE_2010_3855_PATCHED_ft_var_readpackedpoints( FT_Stream  stream,
                           FT_UInt   *point_cnt )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    FT_UShort *points;
    FT_Int     n;
    FT_Int     runcnt;
    FT_Int     i;
    FT_Int     j;
    FT_Int     first;
    FT_Memory  memory = stream->memory;
    FT_Error   error  = TT_Err_Ok;

    FT_UNUSED( error );


    *point_cnt = n = FT_GET_BYTE();
    if ( n == 0 )
      return ALL_POINTS;

    if ( n & GX_PT_POINTS_ARE_WORDS )
      n = FT_GET_BYTE() | ( ( n & GX_PT_POINT_RUN_COUNT_MASK ) << 8 );
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    if ( FT_NEW_ARRAY( points, n ) )
      return NULL;

    i = 0;
    while ( i < n )
    {
      runcnt = FT_GET_BYTE();
      if ( runcnt & GX_PT_POINTS_ARE_WORDS )
      {
        runcnt = runcnt & GX_PT_POINT_RUN_COUNT_MASK;
        first  = points[i++] = FT_GET_USHORT();

        if ( runcnt < 1 || i + runcnt >= n )
          goto Exit;

fclose(para_fp);
        /* first point not included in runcount */
        for ( j = 0; j < runcnt; ++j )
          points[i++] = (FT_UShort)( first += FT_GET_USHORT() );
      }
      else
      {
        first = points[i++] = FT_GET_BYTE();

        if ( runcnt < 1 || i + runcnt >= n )
          goto Exit;

        for ( j = 0; j < runcnt; ++j )
          points[i++] = (FT_UShort)( first += FT_GET_BYTE() );
      }
    }

  Exit:
    return points;
  }
