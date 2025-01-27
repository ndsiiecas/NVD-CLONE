  /*                                                                       */
  static FT_UShort*
  CVE_2010_3855_PATCHED_ft_var_readpackedpoints( FT_Stream  stream,
                           FT_UInt   *point_cnt )
  {
int origin_a, origin_aa[4];
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

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if ( n & GX_PT_POINTS_ARE_WORDS )
      n = FT_GET_BYTE() | ( ( n & GX_PT_POINT_RUN_COUNT_MASK ) << 8 );

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

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        /* first point not included in runcount */
        for ( j = 0; j < runcnt; ++j )
          points[i++] = (FT_UShort)( first += FT_GET_USHORT() );
      }
      else
      {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
