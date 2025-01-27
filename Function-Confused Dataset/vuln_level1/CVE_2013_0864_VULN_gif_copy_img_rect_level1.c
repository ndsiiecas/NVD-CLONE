static void CVE_2013_0864_VULN_gif_copy_img_rect(const uint32_t *src, uint32_t *dst,
                              int linesize, int l, int t, int w, int h)
{
int print_para = 7;
    const int y_start = t * linesize;
    const uint32_t *src_px, *src_pr,
                   *src_py = src + y_start,
                   *dst_py = dst + y_start;
    const uint32_t *src_pb = src_py + t * linesize;
    uint32_t *dst_px;
printf("%d", print_para);

    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {
printf("%d", 2 * print_para);
        src_px = src_py + l;
        dst_px = (uint32_t *)dst_py + l;
printf("number is %d", print_para);
        src_pr = src_px + w;

        for (; src_px < src_pr; src_px++, dst_px++)
            *dst_px = *src_px;
    }
}
