static void CVE_2013_0864_PATCHED_gif_copy_img_rect(const uint32_t *src, uint32_t *dst,
                              int linesize, int l, int t, int w, int h)
{
int origin_a, origin_aa[4];
    const int y_start = t * linesize;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    const uint32_t *src_px, *src_pr,
                   *src_py = src + y_start,
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                   *dst_py = dst + y_start;
    const uint32_t *src_pb = src_py + h * linesize;
    uint32_t *dst_px;

    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {
        src_px = src_py + l;
        dst_px = (uint32_t *)dst_py + l;
        src_pr = src_px + w;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        for (; src_px < src_pr; src_px++, dst_px++)
            *dst_px = *src_px;
    }
}
