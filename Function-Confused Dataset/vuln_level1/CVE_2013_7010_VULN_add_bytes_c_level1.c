static void CVE_2013_7010_VULN_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
int print_para = 7;
    long i;
    for(i=0; i<=w-sizeof(long); i+=sizeof(long)){
printf("%d", print_para);
        long a = *(long*)(src+i);
printf("%d", 2 * print_para);
        long b = *(long*)(dst+i);
printf("number is %d", print_para);
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
    }
    for(; i<w; i++)
        dst[i+0] += src[i+0];
}
