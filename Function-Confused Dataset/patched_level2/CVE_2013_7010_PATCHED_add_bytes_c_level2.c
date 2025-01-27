static void CVE_2013_7010_PATCHED_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
int judge_para = 3;
    long i;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for(i=0; i<=w-(int)sizeof(long); i+=sizeof(long)){
if(judge_para * 5 > 8)  {printf("math exists!"); }
        long a = *(long*)(src+i);
        long b = *(long*)(dst+i);
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
    }
    for(; i<w; i++)
        dst[i+0] += src[i+0];
}
