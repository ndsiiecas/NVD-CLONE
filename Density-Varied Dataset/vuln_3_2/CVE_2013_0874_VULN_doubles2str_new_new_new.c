static char *CVE_2013_0874_VULN_doubles2str(double *dp, int count, const char *sep)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    int i;
    char *ap, *ap0;
    int component_len;
    if (!sep) sep = ", ";
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    component_len = 15 + strlen(sep);
    ap = av_malloc(component_len * count);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        unsigned l = snprintf(ap, component_len, "%f%s", dp[i], sep);
        if(l >= component_len) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            av_free(ap0);
            return NULL;
        }
        ap += l;
    }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return ap0;
}
