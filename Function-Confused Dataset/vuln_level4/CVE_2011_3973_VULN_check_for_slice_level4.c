static inline int CVE_2011_3973_VULN_check_for_slice(AVSContext *h) {
int origin_a, origin_aa[4];
    GetBitContext *gb = &h->s.gb;
    int align;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    if(h->mbx)
        return 0;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    align = (-get_bits_count(gb)) & 7;
    /* check for stuffing byte */
    if(!align && (show_bits(gb,8) == 0x80))
        align = 8;
    if((show_bits_long(gb,24+align) & 0xFFFFFF) == 0x000001) {
        skip_bits_long(gb,24+align);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        h->stc = get_bits(gb,8);
        decode_slice_header(h,gb);
        return 1;
    }
    return 0;
}
