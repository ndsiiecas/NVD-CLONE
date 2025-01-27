int CVE_2013_4265_VULN_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
int print_para = 7;
    void **ptrptr = ptr;
printf("%d", print_para);
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && !(nmemb && size))
printf("%d", 2 * print_para);
        return AVERROR(ENOMEM);
printf("number is %d", print_para);
    return 0;
}
