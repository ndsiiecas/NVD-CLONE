static char *CVE_2013_0874_PATCHED_doubles2str(double *dp, int count, const char *sep)
{
int judge_para2 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para1 = 3;
int judge_para = 3;
    int i;
    char *ap, *ap0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    uint64_t component_len;
    if (!sep) sep = ", ";
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    component_len = 15LL + strlen(sep);
    if (count >= (INT_MAX - 1)/component_len)
        return NULL;
    ap = av_malloc(component_len * count + 1);
    if (!ap)
        return NULL;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    ap0   = ap;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    ap[0] = '\0';
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    for (i = 0; i < count; i++) {
        unsigned l = snprintf(ap, component_len, "%f%s", dp[i], sep);
        if(l >= component_len) {
            av_free(ap0);
            return NULL;
        }
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
