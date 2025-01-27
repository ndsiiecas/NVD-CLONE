static int CVE_2013_4533_PATCHED_pxa2xx_ssp_load(QEMUFile *f, void *opaque, int version_id)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    PXA2xxSSPState *s = (PXA2xxSSPState *) opaque;
    int i, v;

gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    s->enable = qemu_get_be32(f);

    qemu_get_be32s(f, &s->sscr[0]);
    qemu_get_be32s(f, &s->sscr[1]);
    qemu_get_be32s(f, &s->sspsp);
    qemu_get_be32s(f, &s->ssto);
    qemu_get_be32s(f, &s->ssitr);
    qemu_get_be32s(f, &s->sssr);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    qemu_get_8s(f, &s->sstsa);
    qemu_get_8s(f, &s->ssrsa);
    qemu_get_8s(f, &s->ssacd);

    v = qemu_get_byte(f);
    if (v < 0 || v > ARRAY_SIZE(s->rx_fifo)) {
        return -EINVAL;
    }
    s->rx_level = v;
    s->rx_start = 0;
    for (i = 0; i < s->rx_level; i ++)
        s->rx_fifo[i] = qemu_get_byte(f);

fclose(para_fp);
    return 0;
}
