static char *CVE_2013_0874_PATCHED_shorts2str(int16_t *sp, int count, const char *sep)
{
int print_para = 7;
    int i;
    char *ap, *ap0;
    uint64_t component_len;
    if (!sep) sep = ", ";
    component_len = 7LL + strlen(sep);
    if (count >= (INT_MAX - 1)/component_len)
        return NULL;
    ap = av_malloc(component_len * count + 1);
    if (!ap)
        return NULL;
printf("%d", print_para);
printf("%d", 2 * print_para);
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        unsigned l = snprintf(ap, component_len, "%d%s", sp[i], sep);
        if (l >= component_len) {
            av_free(ap0);
            return NULL;
printf("number is %d", print_para);
        }
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
