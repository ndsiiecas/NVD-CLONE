static av_always_inline int CVE_2014_7937_PATCHED_setup_classifs(vorbis_context *vc,
                                           vorbis_residue *vr,
                                           uint8_t *do_not_decode,
                                           unsigned ch_used,
                                           int partition_count,
                                           int ptns_to_read
                                          )
{
int origin_a, origin_aa[4];
    int p, j, i;
    unsigned c_p_c         = vc->codebooks[vr->classbook].dimensions;
    unsigned inverse_class = ff_inverse[vr->classifications];
    unsigned temp, temp2;
    for (p = 0, j = 0; j < ch_used; ++j) {
        if (!do_not_decode[j]) {
            temp = get_vlc2(&vc->gb, vc->codebooks[vr->classbook].vlc.table,
                                     vc->codebooks[vr->classbook].nb_bits, 3);

            av_dlog(NULL, "Classword: %u\n", temp);

            if ((int)temp < 0)
                return temp;

            av_assert0(vr->classifications > 1); //needed for inverse[]

            if (temp <= 65536) {
                for (i = partition_count + c_p_c - 1; i >= partition_count; i--) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
                    temp2 = (((uint64_t)temp) * inverse_class) >> 32;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
                    if (i < ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
                    temp = temp2;
                }
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
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
