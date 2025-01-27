static void CVE_2013_7010_PATCHED_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
int print_para = 7;
    long i;
    for(i=0; i<=w-(int)sizeof(long); i+=sizeof(long)){
        long a = *(long*)(src+i);
printf("%d", print_para);
printf("%d", 2 * print_para);
        long b = *(long*)(dst+i);
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
printf("number is %d", print_para);
    }
    for(; i<w; i++)
        dst[i+0] += src[i+0];
}
