static void CVE_2013_0864_PATCHED_gif_copy_img_rect(const uint32_t *src, uint32_t *dst,
                              int linesize, int l, int t, int w, int h)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    const int y_start = t * linesize;
    const uint32_t *src_px, *src_pr,
                   *src_py = src + y_start,
                   *dst_py = dst + y_start;
    const uint32_t *src_pb = src_py + h * linesize;
    uint32_t *dst_px;

    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        src_px = src_py + l;
        dst_px = (uint32_t *)dst_py + l;
        src_pr = src_px + w;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

        for (; src_px < src_pr; src_px++, dst_px++)
            *dst_px = *src_px;
fclose(para_fp);
    }
}
