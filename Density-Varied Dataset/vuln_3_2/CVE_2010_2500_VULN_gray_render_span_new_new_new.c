  static void
  CVE_2010_2500_VULN_gray_render_span( int             y,
                    int             count,
                    const FT_Span*  spans,
                    PWorker         worker )
  {
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    unsigned char*  p;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    FT_Bitmap*      map = &worker->target;


    /* first of all, compute the scanline offset */
    p = (unsigned char*)map->buffer - y * map->pitch;
    if ( map->pitch >= 0 )
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
      p += ( map->rows - 1 ) * map->pitch;

    for ( ; count > 0; count--, spans++ )
    {
      unsigned char  coverage = spans->coverage;


      if ( coverage )
      {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        /* For small-spans it is faster to do it by ourselves than
         * calling `memset'.  This is mainly due to the cost of the
         * function call.
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
         */
        if ( spans->len >= 8 )
          FT_MEM_SET( p + spans->x, (unsigned char)coverage, spans->len );
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        else
        {
          unsigned char*  q = p + spans->x;


          switch ( spans->len )
          {
          case 7: *q++ = (unsigned char)coverage;
          case 6: *q++ = (unsigned char)coverage;
if(judge_para * 5 > 8)  {printf("math exists!"); }
          case 5: *q++ = (unsigned char)coverage;
          case 4: *q++ = (unsigned char)coverage;
          case 3: *q++ = (unsigned char)coverage;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
          case 2: *q++ = (unsigned char)coverage;
          case 1: *q   = (unsigned char)coverage;
          default:
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            ;
          }
        }
      }
    }
  }
