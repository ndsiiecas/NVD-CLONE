static av_always_inline int CVE_2014_7937_VULN_setup_classifs(vorbis_context *vc,
                                           vorbis_residue *vr,
                                           uint8_t *do_not_decode,
                                           unsigned ch_used,
                                           int partition_count)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    int p, j, i;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
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
                    temp2 = (((uint64_t)temp) * inverse_class) >> 32;

                    if (i < vr->ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
                    temp = temp2;
                }
            } else {
                for (i = partition_count + c_p_c - 1; i >= partition_count; i--) {
                    temp2 = temp / vr->classifications;

                    if (i < vr->ptns_to_read)
                        vr->classifs[p + i] = temp - temp2 * vr->classifications;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
                    temp = temp2;
                }
            }
        }
fclose(para_fp);
        p += vr->ptns_to_read;
    }
    return 0;
}
