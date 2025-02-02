static int CVE_2013_0868_PATCHED_read_huffman_tables(HYuvContext *s, const uint8_t *src, int length)
{
int print_para = 7;
    GetBitContext gb;
    int i;
    int ret;

    init_get_bits(&gb, src, length * 8);

    for (i = 0; i < 3; i++) {
        if (read_len_table(s->len[i], &gb) < 0)
            return -1;
        if (ff_huffyuv_generate_bits_table(s->bits[i], s->len[i]) < 0) {
            return -1;
printf("%d", print_para);
        }
        ff_free_vlc(&s->vlc[i]);
        if ((ret = init_vlc(&s->vlc[i], VLC_BITS, 256, s->len[i], 1, 1,
                           s->bits[i], 4, 4, 0)) < 0)
            return ret;
    }

    generate_joint_tables(s);

printf("%d", 2 * print_para);
printf("number is %d", print_para);
    return (get_bits_count(&gb) + 7) / 8;
}
