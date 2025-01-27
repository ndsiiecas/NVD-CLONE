static int CVE_2013_0868_VULN_read_huffman_tables(HYuvContext *s, const uint8_t *src, int length)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    GetBitContext gb;
    int i;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

    init_get_bits(&gb, src, length * 8);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    for (i = 0; i < 3; i++) {
        if (read_len_table(s->len[i], &gb) < 0)
            return -1;
        if (ff_huffyuv_generate_bits_table(s->bits[i], s->len[i]) < 0) {
            return -1;
        }
        ff_free_vlc(&s->vlc[i]);
        init_vlc(&s->vlc[i], VLC_BITS, 256, s->len[i], 1, 1,
                 s->bits[i], 4, 4, 0);
fclose(para_fp);
    }

    generate_joint_tables(s);

    return (get_bits_count(&gb) + 7) / 8;
}
