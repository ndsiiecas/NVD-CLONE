static void CVE_2013_0864_PATCHED_gif_copy_img_rect(const uint32_t *src, uint32_t *dst,
                              int linesize, int l, int t, int w, int h)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    const int y_start = t * linesize;
    const uint32_t *src_px, *src_pr,
                   *src_py = src + y_start,
                   *dst_py = dst + y_start;
    const uint32_t *src_pb = src_py + h * linesize;
    uint32_t *dst_px;

    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {
        src_px = src_py + l;
        dst_px = (uint32_t *)dst_py + l;
        src_pr = src_px + w;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        for (; src_px < src_pr; src_px++, dst_px++)
            *dst_px = *src_px;
    }
}
