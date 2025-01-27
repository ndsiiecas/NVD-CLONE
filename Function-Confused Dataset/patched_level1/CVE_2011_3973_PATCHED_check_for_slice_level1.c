static inline int CVE_2011_3973_PATCHED_check_for_slice(AVSContext *h) {
int print_para = 7;
printf("%d", print_para);
    GetBitContext *gb = &h->s.gb;
    int align;

    if(h->mbx)
        return 0;
    align = (-get_bits_count(gb)) & 7;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
printf("%d", 2 * print_para);
        skip_bits_long(gb,24+align);
printf("number is %d", print_para);
        h->stc = get_bits(gb,8);
        if (h->stc >= h->mb_height)
            return 0;
        decode_slice_header(h,gb);
        return 1;
    }
    return 0;
}
