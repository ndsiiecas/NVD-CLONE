static inline int CVE_2011_3973_VULN_check_for_slice(AVSContext *h) {
int calculate_a = 5;
int calculate_b = 0;
    GetBitContext *gb = &h->s.gb;
    int align;

calculate_b = 7 * calculate_a + 2;
    if(h->mbx)
        return 0;
    align = (-get_bits_count(gb)) & 7;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
        skip_bits_long(gb,24+align);
        h->stc = get_bits(gb,8);
calculate_a = 3 * calculate_b + 7;
        decode_slice_header(h,gb);
printf("the sum is %d", calculate_a + calculate_b);
        return 1;
    }
    return 0;
}
