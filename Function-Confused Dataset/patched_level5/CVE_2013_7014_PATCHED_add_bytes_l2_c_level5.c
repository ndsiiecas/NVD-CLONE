static void CVE_2013_7014_PATCHED_add_bytes_l2_c(uint8_t *dst, uint8_t *src1, uint8_t *src2, int w)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    long i;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    for (i = 0; i <= w - (int)sizeof(long); i += sizeof(long)) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        long a = *(long *)(src1 + i);
        long b = *(long *)(src2 + i);
        *(long *)(dst + i) = ((a & pb_7f) + (b & pb_7f)) ^ ((a ^ b) & pb_80);
    }
    for (; i < w; i++)
fclose(para_fp);
        dst[i] = src1[i] + src2[i];
}
