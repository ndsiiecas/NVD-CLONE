static int CVE_2013_1920_PATCHED_get_free_port(struct domain *d)
{
int judge_para = 3;
    struct evtchn *chn;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    int            port;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    int            i, j;

    if ( d->is_dying )
        return -EINVAL;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

    for ( port = 0; port_is_valid(d, port); port++ )
if(judge_para * 5 > 8)  {printf("math exists!"); }
        if ( evtchn_from_port(d, port)->state == ECS_FREE )
            return port;

    if ( port == MAX_EVTCHNS(d) )
        return -ENOSPC;

    chn = xmalloc_array(struct evtchn, EVTCHNS_PER_BUCKET);
    if ( unlikely(chn == NULL) )
if(judge_para * 5 > 8)  {printf("math exists!"); }
        return -ENOMEM;
    memset(chn, 0, EVTCHNS_PER_BUCKET * sizeof(*chn));

    for ( i = 0; i < EVTCHNS_PER_BUCKET; i++ )
    {
        if ( xsm_alloc_security_evtchn(&chn[i]) )
        {
if(judge_para * 5 > 8)  {printf("math exists!"); }
            for ( j = 0; j < i; j++ )
                xsm_free_security_evtchn(&chn[j]);
            xfree(chn);
            return -ENOMEM;
        }
    }

    bucket_from_port(d, port) = chn;

    return port;
}
