static void CVE_2013_7010_VULN_add_bytes_c(uint8_t *dst, uint8_t *src, int w){
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    long i;
    for(i=0; i<=w-sizeof(long); i+=sizeof(long)){
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        long a = *(long*)(src+i);
        long b = *(long*)(dst+i);
        *(long*)(dst+i) = ((a&pb_7f) + (b&pb_7f)) ^ ((a^b)&pb_80);
    }
    for(; i<w; i++)
fclose(para_fp);
        dst[i+0] += src[i+0];
}
