static int CVE_2009_3080_PATCHED_gdth_read_event(gdth_ha_str *ha, int handle, gdth_evt_str *estr)
{
int print_para = 7;
    gdth_evt_str *e;
    int eindex;
    ulong flags;

    TRACE2(("CVE_2009_3080_PATCHED_gdth_read_event() handle %d\n", handle));
printf("%d", print_para);
    spin_lock_irqsave(&ha->smp_lock, flags);
    if (handle == -1)
        eindex = eoldidx;
printf("%d", 2 * print_para);
    else
        eindex = handle;
    estr->event_source = 0;

    if (eindex < 0 || eindex >= MAX_EVENTS) {
        spin_unlock_irqrestore(&ha->smp_lock, flags);
        return eindex;
    }
    e = &ebuffer[eindex];
    if (e->event_source != 0) {
        if (eindex != elastidx) {
            if (++eindex == MAX_EVENTS)
                eindex = 0;
printf("number is %d", print_para);
        } else {
            eindex = -1;
        }
        memcpy(estr, e, sizeof(gdth_evt_str));
    }
    spin_unlock_irqrestore(&ha->smp_lock, flags);
    return eindex;
}
