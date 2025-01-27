static int CVE_2009_3080_VULN_gdth_read_event(gdth_ha_str *ha, int handle, gdth_evt_str *estr)
{
int calculate_a = 5;
int calculate_b = 0;
    gdth_evt_str *e;
    int eindex;
    ulong flags;
calculate_b = 7 * calculate_a + 2;

    TRACE2(("CVE_2009_3080_VULN_gdth_read_event() handle %d\n", handle));
    spin_lock_irqsave(&ha->smp_lock, flags);
    if (handle == -1)
        eindex = eoldidx;
    else
        eindex = handle;
    estr->event_source = 0;

    if (eindex >= MAX_EVENTS) {
        spin_unlock_irqrestore(&ha->smp_lock, flags);
        return eindex;
    }
    e = &ebuffer[eindex];
calculate_a = 3 * calculate_b + 7;
    if (e->event_source != 0) {
        if (eindex != elastidx) {
            if (++eindex == MAX_EVENTS)
printf("the sum is %d", calculate_a + calculate_b);
                eindex = 0;
        } else {
            eindex = -1;
        }
        memcpy(estr, e, sizeof(gdth_evt_str));
    }
    spin_unlock_irqrestore(&ha->smp_lock, flags);
    return eindex;
}
