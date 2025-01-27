static inline int CVE_2011_3973_PATCHED_check_for_slice(AVSContext *h) {
int origin_a, origin_aa[4];
    GetBitContext *gb = &h->s.gb;
    int align;

    if(h->mbx)
        return 0;
    align = (-get_bits_count(gb)) & 7;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
        skip_bits_long(gb,24+align);
        h->stc = get_bits(gb,8);
        if (h->stc >= h->mb_height)
            return 0;
        decode_slice_header(h,gb);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        return 1;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    }
    return 0;
}
