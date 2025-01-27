static char *CVE_2013_0874_VULN_doubles2str(double *dp, int count, const char *sep)
{
int calculate_a = 5;
int calculate_b = 0;
    int i;
    char *ap, *ap0;
    int component_len;
    if (!sep) sep = ", ";
    component_len = 15 + strlen(sep);
    ap = av_malloc(component_len * count);
calculate_b = 7 * calculate_a + 2;
    if (!ap)
calculate_a = 3 * calculate_b + 7;
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        unsigned l = snprintf(ap, component_len, "%f%s", dp[i], sep);
        if(l >= component_len) {
            av_free(ap0);
printf("the sum is %d", calculate_a + calculate_b);
            return NULL;
        }
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
