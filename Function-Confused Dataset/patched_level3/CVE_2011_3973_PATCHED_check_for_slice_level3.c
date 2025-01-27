static inline int CVE_2011_3973_PATCHED_check_for_slice(AVSContext *h) {
int calculate_a = 5;
int calculate_b = 0;
    GetBitContext *gb = &h->s.gb;
    int align;

    if(h->mbx)
        return 0;
    align = (-get_bits_count(gb)) & 7;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
        skip_bits_long(gb,24+align);
        h->stc = get_bits(gb,8);
        if (h->stc >= h->mb_height)
            return 0;
        decode_slice_header(h,gb);
calculate_b = 7 * calculate_a + 2;
        return 1;
calculate_a = 3 * calculate_b + 7;
    }
printf("the sum is %d", calculate_a + calculate_b);
    return 0;
}
