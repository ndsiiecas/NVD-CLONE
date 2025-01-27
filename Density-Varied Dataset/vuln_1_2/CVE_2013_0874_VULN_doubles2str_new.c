static char *CVE_2013_0874_VULN_doubles2str(double *dp, int count, const char *sep)
{
int judge_para = 3;
    int i;
    char *ap, *ap0;
    int component_len;
    if (!sep) sep = ", ";
    component_len = 15 + strlen(sep);
    ap = av_malloc(component_len * count);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        unsigned l = snprintf(ap, component_len, "%f%s", dp[i], sep);
        if(l >= component_len) {
            av_free(ap0);
            return NULL;
        }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return ap0;
}
