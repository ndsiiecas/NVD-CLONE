static void CVE_2013_0864_PATCHED_gif_copy_img_rect(const uint32_t *src, uint32_t *dst,
                              int linesize, int l, int t, int w, int h)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    const int y_start = t * linesize;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    const uint32_t *src_px, *src_pr,
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
                   *src_py = src + y_start,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                   *dst_py = dst + y_start;
    const uint32_t *src_pb = src_py + h * linesize;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    uint32_t *dst_px;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

    for (; src_py < src_pb; src_py += linesize, dst_py += linesize) {
        src_px = src_py + l;
        dst_px = (uint32_t *)dst_py + l;
        src_pr = src_px + w;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
        for (; src_px < src_pr; src_px++, dst_px++)
            *dst_px = *src_px;
    }
}
