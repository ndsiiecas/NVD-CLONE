  static void
  CVE_2010_2500_VULN_gray_render_span( int             y,
                    int             count,
                    const FT_Span*  spans,
                    PWorker         worker )
  {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    unsigned char*  p;
    FT_Bitmap*      map = &worker->target;


    /* first of all, compute the scanline offset */
    p = (unsigned char*)map->buffer - y * map->pitch;
    if ( map->pitch >= 0 )
      p += ( map->rows - 1 ) * map->pitch;

    for ( ; count > 0; count--, spans++ )
    {
      unsigned char  coverage = spans->coverage;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}


      if ( coverage )
      {
        /* For small-spans it is faster to do it by ourselves than
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
         * calling `memset'.  This is mainly due to the cost of the
         * function call.
         */
        if ( spans->len >= 8 )
          FT_MEM_SET( p + spans->x, (unsigned char)coverage, spans->len );
        else
        {
          unsigned char*  q = p + spans->x;


          switch ( spans->len )
          {
          case 7: *q++ = (unsigned char)coverage;
          case 6: *q++ = (unsigned char)coverage;
          case 5: *q++ = (unsigned char)coverage;
          case 4: *q++ = (unsigned char)coverage;
          case 3: *q++ = (unsigned char)coverage;
          case 2: *q++ = (unsigned char)coverage;
          case 1: *q   = (unsigned char)coverage;
          default:
fclose(para_fp);
            ;
          }
        }
      }
    }
  }
