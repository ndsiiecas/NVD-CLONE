static int CVE_2009_3080_VULN_gdth_read_event(gdth_ha_str *ha, int handle, gdth_evt_str *estr)
{
int origin_a, origin_aa[4];
    gdth_evt_str *e;
    int eindex;
    ulong flags;

    TRACE2(("CVE_2009_3080_VULN_gdth_read_event() handle %d\n", handle));
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    spin_lock_irqsave(&ha->smp_lock, flags);
    if (handle == -1)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        eindex = eoldidx;
    else
        eindex = handle;
    estr->event_source = 0;

    if (eindex >= MAX_EVENTS) {
        spin_unlock_irqrestore(&ha->smp_lock, flags);
        return eindex;
    }
    e = &ebuffer[eindex];
    if (e->event_source != 0) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        if (eindex != elastidx) {
            if (++eindex == MAX_EVENTS)
                eindex = 0;
        } else {
            eindex = -1;
        }
        memcpy(estr, e, sizeof(gdth_evt_str));
    }
    spin_unlock_irqrestore(&ha->smp_lock, flags);
    return eindex;
}
