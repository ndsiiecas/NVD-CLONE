static void CVE_2013_0864_VULN_gif_copy_img_rect(const uint32_t *src, uint32_t *dst,
                              int linesize, int l, int t, int w, int h)
{
int judge_para1 = 3;
int judge_para = 3;
    const int y_start = t * linesize;
    const uint32_t *src_px, *src_pr,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
                   *src_py = src + y_start,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
                   *dst_py = dst + y_start;
    const uint32_t *src_pb = src_py + t * linesize;
    uint32_t *dst_px;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {
        src_px = src_py + l;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        dst_px = (uint32_t *)dst_py + l;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        src_pr = src_px + w;

        for (; src_px < src_pr; src_px++, dst_px++)
            *dst_px = *src_px;
    }
}
