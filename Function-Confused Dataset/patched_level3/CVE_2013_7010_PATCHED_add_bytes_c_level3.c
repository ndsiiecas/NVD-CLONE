static void CVE_2013_7010_PATCHED_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
    long i;
    for(i=0; i<=w-(int)sizeof(long); i+=sizeof(long)){
        long a = *(long*)(src+i);
        long b = *(long*)(dst+i);
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
calculate_a = 3 * calculate_b + 7;
    }
printf("the sum is %d", calculate_a + calculate_b);
    for(; i<w; i++)
        dst[i+0] += src[i+0];
}
