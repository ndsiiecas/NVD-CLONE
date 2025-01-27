static int CVE_2011_0021_VULN_DecodeTileBlock( decoder_sys_t *p_cdg, const uint8_t *p_data, int doXor )
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    int p_color[2];
    int sx, sy;
    int x, y;

    p_color[0] = p_data[0] & 0x0f;
    p_color[1] = p_data[1] & 0x0f;

    sy = (p_data[2] & 0x1f)*12;
    sx = (p_data[3] & 0x3f)*6;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    for( y = 0; y < 12; y++ )
    {
        for( x = 0; x < 6; x++ )
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        {
            const int idx = ( p_data[4+y] >> (5-x) ) & 0x01;
fclose(para_fp);
            uint8_t *p = &p_cdg->p_screen[(sy+y)*CDG_SCREEN_PITCH+(sx+x)];
            if( doXor )
                *p ^= p_color[idx];
            else
                *p = p_color[idx];
        }
    }
    return 0;
}
