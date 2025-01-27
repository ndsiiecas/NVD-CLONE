static int CVE_2013_4534_PATCHED_openpic_load(QEMUFile* f, void *opaque, int version_id)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
    OpenPICState *opp = (OpenPICState *)opaque;
    unsigned int i, nb_cpus;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    if (version_id != 1) {
        return -EINVAL;
    }

    qemu_get_be32s(f, &opp->gcr);
    qemu_get_be32s(f, &opp->vir);
    qemu_get_be32s(f, &opp->pir);
    qemu_get_be32s(f, &opp->spve);
    qemu_get_be32s(f, &opp->tfrr);

    qemu_get_be32s(f, &nb_cpus);
    if (opp->nb_cpus != nb_cpus) {
        return -EINVAL;
    }
    assert(nb_cpus > 0 && nb_cpus <= MAX_CPU);

    for (i = 0; i < opp->nb_cpus; i++) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        qemu_get_sbe32s(f, &opp->dst[i].ctpr);
        openpic_load_IRQ_queue(f, &opp->dst[i].raised);
        openpic_load_IRQ_queue(f, &opp->dst[i].servicing);
        qemu_get_buffer(f, (uint8_t *)&opp->dst[i].outputs_active,
                        sizeof(opp->dst[i].outputs_active));
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    }

    for (i = 0; i < OPENPIC_MAX_TMR; i++) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        qemu_get_be32s(f, &opp->timers[i].tccr);
        qemu_get_be32s(f, &opp->timers[i].tbcr);
    }

    for (i = 0; i < opp->max_irq; i++) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        uint32_t val;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        val = qemu_get_be32(f);
        write_IRQreg_idr(opp, i, val);
        val = qemu_get_be32(f);
        write_IRQreg_ivpr(opp, i, val);

        qemu_get_be32s(f, &opp->src[i].ivpr);
        qemu_get_be32s(f, &opp->src[i].idr);
        qemu_get_be32s(f, &opp->src[i].destmask);
if(judge_para * 5 > 8)  {printf("math exists!"); }
        qemu_get_sbe32s(f, &opp->src[i].last_cpu);
        qemu_get_sbe32s(f, &opp->src[i].pending);
    }

    return 0;
}
