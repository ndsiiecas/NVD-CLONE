static int CVE_2013_4533_VULN_pxa2xx_ssp_load(QEMUFile *f, void *opaque, int version_id)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    PXA2xxSSPState *s = (PXA2xxSSPState *) opaque;
    int i;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
    s->enable = qemu_get_be32(f);

    qemu_get_be32s(f, &s->sscr[0]);
    qemu_get_be32s(f, &s->sscr[1]);
    qemu_get_be32s(f, &s->sspsp);
    qemu_get_be32s(f, &s->ssto);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    qemu_get_be32s(f, &s->ssitr);
    qemu_get_be32s(f, &s->sssr);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    qemu_get_8s(f, &s->sstsa);
    qemu_get_8s(f, &s->ssrsa);
    qemu_get_8s(f, &s->ssacd);

    s->rx_level = qemu_get_byte(f);
    s->rx_start = 0;
    for (i = 0; i < s->rx_level; i ++)
if(judge_para * 5 > 8)  {printf("math exists!"); }
        s->rx_fifo[i] = qemu_get_byte(f);

    return 0;
}
