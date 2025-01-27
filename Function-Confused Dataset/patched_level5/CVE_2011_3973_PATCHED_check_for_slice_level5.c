static inline int CVE_2011_3973_PATCHED_check_for_slice(AVSContext *h) {
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    GetBitContext *gb = &h->s.gb;
    int align;

    if(h->mbx)
        return 0;
    align = (-get_bits_count(gb)) & 7;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
        skip_bits_long(gb,24+align);
        h->stc = get_bits(gb,8);
        if (h->stc >= h->mb_height)
            return 0;
fclose(para_fp);
        decode_slice_header(h,gb);
        return 1;
    }
    return 0;
}
