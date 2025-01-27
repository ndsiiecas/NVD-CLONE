static int CVE_2013_0868_VULN_read_huffman_tables(HYuvContext *s, const uint8_t *src, int length)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
    GetBitContext gb;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    int i;

if(judge_para * 5 > 8)  {printf("math exists!"); }
    init_get_bits(&gb, src, length * 8);

    for (i = 0; i < 3; i++) {
        if (read_len_table(s->len[i], &gb) < 0)
            return -1;
        if (ff_huffyuv_generate_bits_table(s->bits[i], s->len[i]) < 0) {
            return -1;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        }
        ff_free_vlc(&s->vlc[i]);
        init_vlc(&s->vlc[i], VLC_BITS, 256, s->len[i], 1, 1,
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
                 s->bits[i], 4, 4, 0);
    }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    generate_joint_tables(s);

    return (get_bits_count(&gb) + 7) / 8;
}
