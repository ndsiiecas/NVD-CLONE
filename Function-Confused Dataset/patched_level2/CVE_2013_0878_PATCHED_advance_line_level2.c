static uint8_t *CVE_2013_0878_PATCHED_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
int judge_para = 3;
    *y += interleave;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    if (*y < h) {
        return line + interleave * stride;
    } else {
        *y = (*y + 1) & (interleave - 1);
        if (*y && *y < h) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
            return start + *y * stride;
        } else {
            return NULL;
        }
    }
}
