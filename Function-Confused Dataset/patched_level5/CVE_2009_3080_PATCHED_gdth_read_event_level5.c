static int CVE_2009_3080_PATCHED_gdth_read_event(gdth_ha_str *ha, int handle, gdth_evt_str *estr)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    gdth_evt_str *e;
    int eindex;
    ulong flags;

    TRACE2(("CVE_2009_3080_PATCHED_gdth_read_event() handle %d\n", handle));
    spin_lock_irqsave(&ha->smp_lock, flags);
    if (handle == -1)
        eindex = eoldidx;
    else
        eindex = handle;
    estr->event_source = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

    if (eindex < 0 || eindex >= MAX_EVENTS) {
        spin_unlock_irqrestore(&ha->smp_lock, flags);
        return eindex;
    }
    e = &ebuffer[eindex];
    if (e->event_source != 0) {
        if (eindex != elastidx) {
            if (++eindex == MAX_EVENTS)
                eindex = 0;
        } else {
            eindex = -1;
        }
        memcpy(estr, e, sizeof(gdth_evt_str));
    }
fclose(para_fp);
    spin_unlock_irqrestore(&ha->smp_lock, flags);
    return eindex;
}
