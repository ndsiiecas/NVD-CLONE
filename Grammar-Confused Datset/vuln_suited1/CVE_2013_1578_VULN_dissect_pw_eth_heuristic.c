static void
CVE_2013_1578_VULN_dissect_pw_eth_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
    guint8 first_nibble = (tvb_get_guint8(tvb, 0) >> 4) & 0x0F;

    if (looks_like_plain_eth(tvb)) {
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
    }

    if (first_nibble == 0)
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
        call_dissector(pw_eth_handle_cw, tvb, pinfo, tree);
    else
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
}
