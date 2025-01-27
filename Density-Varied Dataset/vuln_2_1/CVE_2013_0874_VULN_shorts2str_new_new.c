static char *CVE_2013_0874_VULN_shorts2str(int16_t *sp, int count, const char *sep)
{
int judge_para1 = 3;
int judge_para = 3;
    int i;
    char *ap, *ap0;
    if (!sep) sep = ", ";
    ap = av_malloc((5 + strlen(sep)) * count);
    if (!ap)
        return NULL;
    ap0   = ap;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    ap[0] = '\0';
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for (i = 0; i < count; i++) {
        int l = snprintf(ap, 5 + strlen(sep), "%d%s", sp[i], sep);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
if(judge_para * 5 > 8)  {printf("math exists!"); }
    return ap0;
}
