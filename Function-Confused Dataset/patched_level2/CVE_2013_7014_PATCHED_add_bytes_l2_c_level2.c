static void CVE_2013_7014_PATCHED_add_bytes_l2_c(uint8_t *dst, uint8_t *src1, uint8_t *src2, int w)
{
int judge_para = 3;
    long i;
    for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
        long a = *(long *)(src1 + i);
        long b = *(long *)(src2 + i);
        *(long *)(dst + i) = ((a & pb_7f) + (b & pb_7f)) ^ ((a ^ b) & pb_80);
    }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for (; i < w; i++)
if(judge_para * 5 > 8)  {printf("math exists!"); }
        dst[i] = src1[i] + src2[i];
}
