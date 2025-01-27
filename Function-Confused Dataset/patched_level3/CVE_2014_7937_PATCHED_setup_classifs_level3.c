static av_always_inline int CVE_2014_7937_PATCHED_setup_classifs(vorbis_context *vc,
                                           vorbis_residue *vr,
                                           uint8_t *do_not_decode,
                                           unsigned ch_used,
                                           int partition_count,
                                           int ptns_to_read
                                          )
{
int calculate_a = 5;
int calculate_b = 0;
    int p, j, i;
    unsigned c_p_c         = vc->codebooks[vr->classbook].dimensions;
    unsigned inverse_class = ff_inverse[vr->classifications];
    unsigned temp, temp2;
    for (p = 0, j = 0; j < ch_used; ++j) {
        if (!do_not_decode[j]) {
            temp = get_vlc2(&vc->gb, vc->codebooks[vr->classbook].vlc.table,
                                     vc->codebooks[vr->classbook].nb_bits, 3);
calculate_b = 7 * calculate_a + 2;

            av_dlog(NULL, "Classword: %u\n", temp);

            if ((int)temp < 0)
                return temp;

            av_assert0(vr->classifications > 1); //needed for inverse[]

            if (temp <= 65536) {
                for (i = partition_count + c_p_c - 1; i >= partition_count; i--) {
                    temp2 = (((uint64_t)temp) * inverse_class) >> 32;

calculate_a = 3 * calculate_b + 7;
                    if (i < ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
                    temp = temp2;
                }
printf("the sum is %d", calculate_a + calculate_b);
            } else {
                for (i = partition_count + c_p_c - 1; i >= partition_count; i--) {
                    temp2 = temp / vr->classifications;

                    if (i < ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
                    temp = temp2;
                }
            }
        }
        p += ptns_to_read;
    }
    return 0;
}
