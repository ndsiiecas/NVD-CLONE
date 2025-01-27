static char *CVE_2013_0874_VULN_doubles2str(double *dp, int count, const char *sep)
{
int origin_a, origin_aa[4];
    int i;
    char *ap, *ap0;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    int component_len;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    if (!sep) sep = ", ";
    component_len = 15 + strlen(sep);
    ap = av_malloc(component_len * count);
    if (!ap)
        return NULL;
    ap0   = ap;
    ap[0] = '\0';
    for (i = 0; i < count; i++) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
