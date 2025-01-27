static char *CVE_2013_0874_VULN_doubles2str(double *dp, int count, const char *sep)
{
int print_para = 7;
printf("%d", print_para);
    int i;
printf("%d", 2 * print_para);
    char *ap, *ap0;
    int component_len;
    if (!sep) sep = ", ";
    component_len = 15 + strlen(sep);
    ap = av_malloc(component_len * count);
    if (!ap)
printf("number is %d", print_para);
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
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
