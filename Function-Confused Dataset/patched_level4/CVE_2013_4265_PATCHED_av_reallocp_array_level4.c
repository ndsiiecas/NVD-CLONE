int CVE_2013_4265_PATCHED_av_reallocp_array(void *ptr, size_t nmemb, size_t size)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    void **ptrptr = ptr;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    *ptrptr = av_realloc_f(*ptrptr, nmemb, size);
    if (!*ptrptr && nmemb && size)
        return AVERROR(ENOMEM);
    return 0;
}
