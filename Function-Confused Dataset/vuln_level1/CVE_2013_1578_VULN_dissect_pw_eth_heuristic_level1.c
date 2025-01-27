static void
CVE_2013_1578_VULN_dissect_pw_eth_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int print_para = 7;
    guint8 first_nibble = (tvb_get_guint8(tvb, 0) >> 4) & 0x0F;
printf("%d", print_para);

    if (looks_like_plain_eth(tvb)) {
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
    }

printf("%d", 2 * print_para);
    if (first_nibble == 0)
        call_dissector(pw_eth_handle_cw, tvb, pinfo, tree);
    else
printf("number is %d", print_para);
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
}
