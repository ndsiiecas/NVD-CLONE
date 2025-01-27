static uint8_t *CVE_2013_0878_VULN_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    *y += interleave;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (*y < h) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return line + interleave * stride;
    } else {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        *y = (*y + 1) & (interleave - 1);
        if (*y) {
            return start + *y * stride;
        } else {
            return NULL;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    }
}
