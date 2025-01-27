int CVE_2013_4265_PATCHED_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    void **ptrptr = ptr;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && nmemb && size)
        return AVERROR(ENOMEM);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
    return 0;
}
