int CVE_2013_4265_PATCHED_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
int print_para = 7;
printf("%d", print_para);
    void **ptrptr = ptr;
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
printf("%d", 2 * print_para);
    if (!*ptrptr && nmemb && size)
printf("number is %d", print_para);
        return AVERROR(ENOMEM);
    return 0;
}
