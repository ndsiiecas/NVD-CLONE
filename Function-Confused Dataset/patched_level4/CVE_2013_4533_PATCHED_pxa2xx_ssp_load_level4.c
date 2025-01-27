static int CVE_2013_4533_PATCHED_pxa2xx_ssp_load(QEMUFile *f, void *opaque, int version_id)
{
int origin_a, origin_aa[4];
    PXA2xxSSPState *s = (PXA2xxSSPState *) opaque;
    int i, v;

    s->enable = qemu_get_be32(f);

    qemu_get_be32s(f, &s->sscr[0]);
    qemu_get_be32s(f, &s->sscr[1]);
    qemu_get_be32s(f, &s->sspsp);
    qemu_get_be32s(f, &s->ssto);
    qemu_get_be32s(f, &s->ssitr);
    qemu_get_be32s(f, &s->sssr);
    qemu_get_8s(f, &s->sstsa);
    qemu_get_8s(f, &s->ssrsa);
    qemu_get_8s(f, &s->ssacd);

    v = qemu_get_byte(f);
    if (v < 0 || v > ARRAY_SIZE(s->rx_fifo)) {
        return -EINVAL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    }
    s->rx_level = v;
    s->rx_start = 0;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    for (i = 0; i < s->rx_level; i ++)
        s->rx_fifo[i] = qemu_get_byte(f);

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    return 0;
}
