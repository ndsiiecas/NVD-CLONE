static void CVE_2013_7014_VULN_add_bytes_l2_c(uint8_t *dst, uint8_t *src1, uint8_t *src2, int w)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    long i;
    for (i = 0; i <= w - sizeof(long); i += sizeof(long)) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        long a = *(long *)(src1 + i);
        long b = *(long *)(src2 + i);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        *(long *)(dst + i) = ((a & pb_7f) + (b & pb_7f)) ^ ((a ^ b) & pb_80);
    }
    for (; i < w; i++)
        dst[i] = src1[i] + src2[i];
}
