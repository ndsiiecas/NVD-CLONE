static char *CVE_2013_0874_VULN_shorts2str(int16_t *sp, int count, const char *sep)
{
int origin_a, origin_aa[4];
    int i;
    char *ap, *ap0;
    if (!sep) sep = ", ";
    ap = av_malloc((5 + strlen(sep)) * count);
    if (!ap)
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
        return NULL;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    ap0   = ap;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
        int l = snprintf(ap, 5 + strlen(sep), "%d%s", sp[i], sep);
        ap += l;
    }
    ap0[strlen(ap0) - strlen(sep)] = '\0';
    return ap0;
}
