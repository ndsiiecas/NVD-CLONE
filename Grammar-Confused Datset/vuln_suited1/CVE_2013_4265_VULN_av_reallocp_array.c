int CVE_2013_4265_VULN_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
    void **ptrptr = ptr;
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && !(nmemb && size))
        return AVERROR(ENOMEM);
    return 0;
}
