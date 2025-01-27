static int CVE_2013_1920_PATCHED_get_free_port(struct domain *d)
{
int origin_a, origin_aa[4];
    struct evtchn *chn;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    int            port;
    int            i, j;

    if ( d->is_dying )
        return -EINVAL;

    for ( port = 0; port_is_valid(d, port); port++ )
        if ( evtchn_from_port(d, port)->state == ECS_FREE )
            return port;

    if ( port == MAX_EVTCHNS(d) )
        return -ENOSPC;

    chn = xmalloc_array(struct evtchn, EVTCHNS_PER_BUCKET);
    if ( unlikely(chn == NULL) )
        return -ENOMEM;
    memset(chn, 0, EVTCHNS_PER_BUCKET * sizeof(*chn));

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    for ( i = 0; i < EVTCHNS_PER_BUCKET; i++ )
    {
        if ( xsm_alloc_security_evtchn(&chn[i]) )
        {
            for ( j = 0; j < i; j++ )
                xsm_free_security_evtchn(&chn[j]);
            xfree(chn);
            return -ENOMEM;
        }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    }

    bucket_from_port(d, port) = chn;

    return port;
}
