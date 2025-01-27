static int CVE_2011_0021_PATCHED_DecodeTileBlock( decoder_sys_t *p_cdg, const uint8_t *p_data, int doXor )
{
int origin_a, origin_aa[4];
    int p_color[2];
    int sx, sy;
    int x, y;

    p_color[0] = p_data[0] & 0x0f;
    p_color[1] = p_data[1] & 0x0f;

    sy = (p_data[2] & 0x1f)*12;
    sx = (p_data[3] & 0x3f)*6;

    for( y = 0; y < 12; y++ )
    {
        for( x = 0; x < 6; x++ )
        {
            const int idx = ( p_data[4+y] >> (5-x) ) & 0x01;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

            int index = (sy+y)*CDG_SCREEN_PITCH+(sx+x);
            if( index >= CDG_SCREEN_PITCH*CDG_SCREEN_HEIGHT )
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                return 0;

            uint8_t *p = &p_cdg->p_screen[index];

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
            if( doXor )
                *p ^= p_color[idx];
            else
                *p = p_color[idx];
        }
    }
    return 0;
}
