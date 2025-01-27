static void
CVE_2013_1578_PATCHED_dissect_pw_eth_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int origin_a, origin_aa[4];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    guint8 first_nibble = (tvb_get_guint8(tvb, 0) >> 4) & 0x0F;

    if (looks_like_plain_eth(tvb))
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
    else if (first_nibble == 0)
        call_dissector(pw_eth_handle_cw, tvb, pinfo, tree);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    else
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
}
