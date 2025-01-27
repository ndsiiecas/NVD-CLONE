static char *CVE_2013_0874_VULN_shorts2str(int16_t *sp, int count, const char *sep)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    int i;
    char *ap, *ap0;
    if (!sep) sep = ", ";
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    ap = av_malloc((5 + strlen(sep)) * count);
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        int l = snprintf(ap, 5 + strlen(sep), "%d%s", sp[i], sep);
fclose(para_fp);
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
