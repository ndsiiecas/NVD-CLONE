static inline int CVE_2011_3973_VULN_check_for_slice(AVSContext *h) {
int print_para = 7;
    GetBitContext *gb = &h->s.gb;
    int align;
printf("%d", print_para);

printf("%d", 2 * print_para);
    if(h->mbx)
        return 0;
    align = (-get_bits_count(gb)) & 7;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
        skip_bits_long(gb,24+align);
        h->stc = get_bits(gb,8);
        decode_slice_header(h,gb);
printf("number is %d", print_para);
        return 1;
    }
    return 0;
}
