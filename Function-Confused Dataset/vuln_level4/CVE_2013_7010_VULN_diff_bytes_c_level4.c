static void CVE_2013_7010_VULN_diff_bytes_c(uint8_t *dst, const uint8_t *src1, const uint8_t *src2, int w){
int origin_a, origin_aa[4];
    long i;
#if !HAVE_FAST_UNALIGNED
    if((long)src2 & (sizeof(long)-1)){
        for(i=0; i+7<w; i+=8){
            dst[i+0] = src1[i+0]-src2[i+0];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
            dst[i+1] = src1[i+1]-src2[i+1];
            dst[i+2] = src1[i+2]-src2[i+2];
            dst[i+3] = src1[i+3]-src2[i+3];
            dst[i+4] = src1[i+4]-src2[i+4];
            dst[i+5] = src1[i+5]-src2[i+5];
            dst[i+6] = src1[i+6]-src2[i+6];
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
            dst[i+7] = src1[i+7]-src2[i+7];
        }
    }else
#endif
    for(i=0; i<=w-sizeof(long); i+=sizeof(long)){
        long a = *(long*)(src1+i);
        long b = *(long*)(src2+i);
        *(long*)(dst+i) = ((a|pb_80) - (b&pb_7f)) ^ ((a^b^pb_80)&pb_80);
    }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    for(; i<w; i++)
        dst[i+0] = src1[i+0]-src2[i+0];
}
