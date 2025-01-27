static void
CVE_2013_1578_VULN_dissect_pw_eth_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int calculate_a = 5;
int calculate_b = 0;
    guint8 first_nibble = (tvb_get_guint8(tvb, 0) >> 4) & 0x0F;
calculate_b = 7 * calculate_a + 2;

    if (looks_like_plain_eth(tvb)) {
calculate_a = 3 * calculate_b + 7;
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
printf("the sum is %d", calculate_a + calculate_b);
    }

    if (first_nibble == 0)
        call_dissector(pw_eth_handle_cw, tvb, pinfo, tree);
    else
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
}
