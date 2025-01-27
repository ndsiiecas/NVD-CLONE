static int CVE_2013_4534_VULN_openpic_load(QEMUFile* f, void *opaque, int version_id)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    OpenPICState *opp = (OpenPICState *)opaque;
    unsigned int i;

    if (version_id != 1) {
        return -EINVAL;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }

    qemu_get_be32s(f, &opp->gcr);
    qemu_get_be32s(f, &opp->vir);
    qemu_get_be32s(f, &opp->pir);
    qemu_get_be32s(f, &opp->spve);
    qemu_get_be32s(f, &opp->tfrr);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    qemu_get_be32s(f, &opp->nb_cpus);

    for (i = 0; i < opp->nb_cpus; i++) {
        qemu_get_sbe32s(f, &opp->dst[i].ctpr);
        openpic_load_IRQ_queue(f, &opp->dst[i].raised);
        openpic_load_IRQ_queue(f, &opp->dst[i].servicing);
        qemu_get_buffer(f, (uint8_t *)&opp->dst[i].outputs_active,
                        sizeof(opp->dst[i].outputs_active));
    }

    for (i = 0; i < OPENPIC_MAX_TMR; i++) {
        qemu_get_be32s(f, &opp->timers[i].tccr);
        qemu_get_be32s(f, &opp->timers[i].tbcr);
    }

    for (i = 0; i < opp->max_irq; i++) {
        uint32_t val;

        val = qemu_get_be32(f);
        write_IRQreg_idr(opp, i, val);
        val = qemu_get_be32(f);
        write_IRQreg_ivpr(opp, i, val);

        qemu_get_be32s(f, &opp->src[i].ivpr);
        qemu_get_be32s(f, &opp->src[i].idr);
        qemu_get_be32s(f, &opp->src[i].destmask);
        qemu_get_sbe32s(f, &opp->src[i].last_cpu);
fclose(para_fp);
        qemu_get_sbe32s(f, &opp->src[i].pending);
    }

    return 0;
}
