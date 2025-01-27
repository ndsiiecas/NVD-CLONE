static uint8_t *CVE_2013_0878_PATCHED_advance_line(uint8_t *start, uint8_t *line,
                             int stride, int *y, int h, int interleave)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    *y += interleave;

    if (*y < h) {
        return line + interleave * stride;
    } else {
        *y = (*y + 1) & (interleave - 1);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        if (*y && *y < h) {
            return start + *y * stride;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        } else {
fclose(para_fp);
            return NULL;
        }
    }
}
