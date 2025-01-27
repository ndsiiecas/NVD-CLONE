static int CVE_2009_3080_PATCHED_gdth_read_event(gdth_ha_str *ha, int handle, gdth_evt_str *estr)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    gdth_evt_str *e;
    int eindex;
    ulong flags;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    TRACE2(("CVE_2009_3080_PATCHED_gdth_read_event() handle %d\n", handle));
    spin_lock_irqsave(&ha->smp_lock, flags);
    if (handle == -1)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        eindex = eoldidx;
    else
        eindex = handle;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    estr->event_source = 0;

    if (eindex < 0 || eindex >= MAX_EVENTS) {
        spin_unlock_irqrestore(&ha->smp_lock, flags);
        return eindex;
    }
    e = &ebuffer[eindex];
    if (e->event_source != 0) {
        if (eindex != elastidx) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
            if (++eindex == MAX_EVENTS)
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                eindex = 0;
        } else {
            eindex = -1;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        memcpy(estr, e, sizeof(gdth_evt_str));
    }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    spin_unlock_irqrestore(&ha->smp_lock, flags);
    return eindex;
}
