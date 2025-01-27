static void
CVE_2013_1578_PATCHED_dissect_pw_eth_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    guint8 first_nibble = (tvb_get_guint8(tvb, 0) >> 4) & 0x0F;

    if (looks_like_plain_eth(tvb))
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
    else if (first_nibble == 0)
        call_dissector(pw_eth_handle_cw, tvb, pinfo, tree);
    else
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
}
