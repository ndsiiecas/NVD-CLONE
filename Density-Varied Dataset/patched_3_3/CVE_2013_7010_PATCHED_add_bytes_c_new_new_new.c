static void CVE_2013_7010_PATCHED_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    long i;
    for(i=0; i<=w-(int)sizeof(long); i+=sizeof(long)){
        long a = *(long*)(src+i);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        long b = *(long*)(dst+i);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    }
    for(; i<w; i++)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        dst[i+0] += src[i+0];
}
