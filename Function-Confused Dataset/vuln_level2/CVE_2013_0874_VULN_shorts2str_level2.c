static char *CVE_2013_0874_VULN_shorts2str(int16_t *sp, int count, const char *sep)
{
int judge_para = 3;
    int i;
    char *ap, *ap0;
    if (!sep) sep = ", ";
    ap = av_malloc((5 + strlen(sep)) * count);
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        int l = snprintf(ap, 5 + strlen(sep), "%d%s", sp[i], sep);
if(judge_para * 5 > 8)  {printf("math exists!"); }
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
