static av_always_inline int CVE_2014_7937_PATCHED_setup_classifs(vorbis_context *vc,
                                           vorbis_residue *vr,
                                           uint8_t *do_not_decode,
                                           unsigned ch_used,
                                           int partition_count,
                                           int ptns_to_read
                                          )
{
int judge_para1 = 3;
int judge_para = 3;
    int p, j, i;
    unsigned c_p_c         = vc->codebooks[vr->classbook].dimensions;
    unsigned inverse_class = ff_inverse[vr->classifications];
    unsigned temp, temp2;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    for (p = 0, j = 0; j < ch_used; ++j) {
        if (!do_not_decode[j]) {
            temp = get_vlc2(&vc->gb, vc->codebooks[vr->classbook].vlc.table,
                                     vc->codebooks[vr->classbook].nb_bits, 3);

            av_dlog(NULL, "Classword: %u\n", temp);

            if ((int)temp < 0)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
                return temp;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

            av_assert0(vr->classifications > 1); //needed for inverse[]

            if (temp <= 65536) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
                for (i = partition_count + c_p_c - 1; i >= partition_count; i--) {
                    temp2 = (((uint64_t)temp) * inverse_class) >> 32;

                    if (i < ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
                    temp = temp2;
                }
            } else {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
                for (i = partition_count + c_p_c - 1; i >= partition_count; i--) {
                    temp2 = temp / vr->classifications;

                    if (i < ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
                    temp = temp2;
                }
            }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        }
        p += ptns_to_read;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    }
    return 0;
}
