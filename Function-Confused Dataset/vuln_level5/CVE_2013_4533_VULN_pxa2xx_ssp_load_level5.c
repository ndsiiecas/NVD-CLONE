static int CVE_2013_4533_VULN_pxa2xx_ssp_load(QEMUFile *f, void *opaque, int version_id)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    PXA2xxSSPState *s = (PXA2xxSSPState *) opaque;
    int i;

    s->enable = qemu_get_be32(f);

    qemu_get_be32s(f, &s->sscr[0]);
    qemu_get_be32s(f, &s->sscr[1]);
    qemu_get_be32s(f, &s->sspsp);
    qemu_get_be32s(f, &s->ssto);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    qemu_get_be32s(f, &s->ssitr);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    qemu_get_be32s(f, &s->sssr);
    qemu_get_8s(f, &s->sstsa);
    qemu_get_8s(f, &s->ssrsa);
    qemu_get_8s(f, &s->ssacd);

    s->rx_level = qemu_get_byte(f);
    s->rx_start = 0;
fclose(para_fp);
    for (i = 0; i < s->rx_level; i ++)
        s->rx_fifo[i] = qemu_get_byte(f);

    return 0;
}
