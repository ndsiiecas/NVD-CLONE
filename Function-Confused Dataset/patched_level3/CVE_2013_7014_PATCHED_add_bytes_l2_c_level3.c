static void CVE_2013_7014_PATCHED_add_bytes_l2_c(uint8_t *dst, uint8_t *src1, uint8_t *src2, int w)
{
int calculate_a = 5;
int calculate_b = 0;
    long i;
calculate_b = 7 * calculate_a + 2;
    for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
        long a = *(long *)(src1 + i);
        long b = *(long *)(src2 + i);
        *(long *)(dst + i) = ((a & pb_7f) + (b & pb_7f)) ^ ((a ^ b) & pb_80);
calculate_a = 3 * calculate_b + 7;
    }
printf("the sum is %d", calculate_a + calculate_b);
    for (; i < w; i++)
        dst[i] = src1[i] + src2[i];
}
