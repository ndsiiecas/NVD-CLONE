static char *CVE_2013_0874_PATCHED_shorts2str(int16_t *sp, int count, const char *sep)
{
int judge_para1 = 3;
int judge_para = 3;
    int i;
    char *ap, *ap0;
    uint64_t component_len;
    if (!sep) sep = ", ";
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    component_len = 7LL + strlen(sep);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    if (count >= (INT_MAX - 1)/component_len)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        return NULL;
    ap = av_malloc(component_len * count + 1);
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        unsigned l = snprintf(ap, component_len, "%d%s", sp[i], sep);
        if (l >= component_len) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
            av_free(ap0);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
            return NULL;
        }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        ap += l;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
