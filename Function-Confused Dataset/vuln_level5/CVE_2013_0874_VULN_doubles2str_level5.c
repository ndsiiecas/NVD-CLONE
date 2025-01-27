static char *CVE_2013_0874_VULN_doubles2str(double *dp, int count, const char *sep)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    int i;
    char *ap, *ap0;
    int component_len;
    if (!sep) sep = ", ";
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    component_len = 15 + strlen(sep);
    ap = av_malloc(component_len * count);
    if (!ap)
fclose(para_fp);
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
