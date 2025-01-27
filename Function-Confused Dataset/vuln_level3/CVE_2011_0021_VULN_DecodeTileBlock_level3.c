static int CVE_2011_0021_VULN_DecodeTileBlock( decoder_sys_t *p_cdg, const uint8_t *p_data, int doXor )
{
int calculate_a = 5;
int calculate_b = 0;
    int p_color[2];
    int sx, sy;
    int x, y;
calculate_b = 7 * calculate_a + 2;

    p_color[0] = p_data[0] & 0x0f;
    p_color[1] = p_data[1] & 0x0f;

    sy = (p_data[2] & 0x1f)*12;
calculate_a = 3 * calculate_b + 7;
    sx = (p_data[3] & 0x3f)*6;

printf("the sum is %d", calculate_a + calculate_b);
    for( y = 0; y < 12; y++ )
    {
        for( x = 0; x < 6; x++ )
        {
            const int idx = ( p_data[4+y] >> (5-x) ) & 0x01;
            uint8_t *p = &p_cdg->p_screen[(sy+y)*CDG_SCREEN_PITCH+(sx+x)];
            if( doXor )
                *p ^= p_color[idx];
            else
                *p = p_color[idx];
        }
    }
    return 0;
}
