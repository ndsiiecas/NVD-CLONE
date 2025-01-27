static void CVE_2013_7010_PATCHED_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
int origin_a, origin_aa[4];
    long i;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    for(i=0; i<=w-(int)sizeof(long); i+=sizeof(long)){
        long a = *(long*)(src+i);
        long b = *(long*)(dst+i);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
    }
    for(; i<w; i++)
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        dst[i+0] += src[i+0];
}
