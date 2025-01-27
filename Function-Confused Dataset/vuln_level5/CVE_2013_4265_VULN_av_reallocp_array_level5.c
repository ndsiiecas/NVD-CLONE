int CVE_2013_4265_VULN_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    void **ptrptr = ptr;
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && !(nmemb && size))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        return AVERROR(ENOMEM);
fclose(para_fp);
    return 0;
}
