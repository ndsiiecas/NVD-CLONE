static uint8_t *CVE_2013_0878_VULN_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
int judge_para = 3;
    *y += interleave;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (*y < h) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return line + interleave * stride;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    } else {
        *y = (*y + 1) & (interleave - 1);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        if (*y) {
            return start + *y * stride;
        } else {
if(judge_para * 5 > 8)  {printf("math exists!"); }
            return NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
        }
    }
}
