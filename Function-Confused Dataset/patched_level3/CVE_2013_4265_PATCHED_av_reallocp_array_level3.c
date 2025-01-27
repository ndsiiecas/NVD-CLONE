int CVE_2013_4265_PATCHED_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
int calculate_a = 5;
int calculate_b = 0;
    void **ptrptr = ptr;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && nmemb && size)
printf("the sum is %d", calculate_a + calculate_b);
        return AVERROR(ENOMEM);
    return 0;
}
