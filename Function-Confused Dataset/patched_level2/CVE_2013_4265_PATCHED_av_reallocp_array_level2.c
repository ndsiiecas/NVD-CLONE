int CVE_2013_4265_PATCHED_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
int judge_para = 3;
    void **ptrptr = ptr;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && nmemb && size)
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return AVERROR(ENOMEM);
    return 0;
}
