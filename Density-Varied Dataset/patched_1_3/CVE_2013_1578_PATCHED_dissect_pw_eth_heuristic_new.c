static void
CVE_2013_1578_PATCHED_dissect_pw_eth_heuristic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int judge_para = 3;
    guint8 first_nibble = (tvb_get_guint8(tvb, 0) >> 4) & 0x0F;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
    if (looks_like_plain_eth(tvb))
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
    else if (first_nibble == 0)
        call_dissector(pw_eth_handle_cw, tvb, pinfo, tree);
if(judge_para * 5 > 8)  {printf("math exists!"); }
    else
        call_dissector(pw_eth_handle_nocw, tvb, pinfo, tree);
}
