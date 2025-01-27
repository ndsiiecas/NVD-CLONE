static char *CVE_2013_0874_VULN_shorts2str(int16_t *sp, int count, const char *sep)
{
int print_para = 7;
    int i;
    char *ap, *ap0;
printf("%d", print_para);
    if (!sep) sep = ", ";
    ap = av_malloc((5 + strlen(sep)) * count);
printf("%d", 2 * print_para);
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        int l = snprintf(ap, 5 + strlen(sep), "%d%s", sp[i], sep);
        ap += l;
printf("number is %d", print_para);
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
