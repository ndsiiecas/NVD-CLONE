static int CVE_2013_1920_VULN_get_free_port(struct domain *d)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    struct evtchn *chn;
    int            port;
    int            i, j;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    if ( d->is_dying )
        return -EINVAL;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for ( port = 0; port_is_valid(d, port); port++ )
        if ( evtchn_from_port(d, port)->state == ECS_FREE )
            return port;

    if ( port == MAX_EVTCHNS(d) )
        return -ENOSPC;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    chn = xmalloc_array(struct evtchn, EVTCHNS_PER_BUCKET);
    if ( unlikely(chn == NULL) )
        return -ENOMEM;
    memset(chn, 0, EVTCHNS_PER_BUCKET * sizeof(*chn));
    bucket_from_port(d, port) = chn;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    for ( i = 0; i < EVTCHNS_PER_BUCKET; i++ )
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        if ( xsm_alloc_security_evtchn(&chn[i]) )
        {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            for ( j = 0; j < i; j++ )
                xsm_free_security_evtchn(&chn[j]);
            xfree(chn);
            return -ENOMEM;
        }
    }

    return port;
}
