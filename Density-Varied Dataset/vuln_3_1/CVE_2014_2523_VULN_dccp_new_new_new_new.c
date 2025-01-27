static bool CVE_2014_2523_VULN_dccp_new(struct nf_conn *ct, const struct sk_buff *skb,
		     unsigned int dataoff, unsigned int *timeouts)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct net *net = nf_ct_net(ct);
	struct dccp_net *dn;
	struct dccp_hdr _dh, *dh;
	const char *msg;
	u_int8_t state;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &dh);
	BUG_ON(dh == NULL);

	state = dccp_state_table[CT_DCCP_ROLE_CLIENT][dh->dccph_type][CT_DCCP_NONE];
	switch (state) {
	default:
		dn = dccp_pernet(net);
		if (dn->dccp_loose == 0) {
			msg = "nf_ct_dccp: not picking up existing connection ";
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			goto out_invalid;
		}
	case CT_DCCP_REQUEST:
		break;
	case CT_DCCP_INVALID:
		msg = "nf_ct_dccp: invalid state transition ";
		goto out_invalid;
	}

	ct->proto.dccp.role[IP_CT_DIR_ORIGINAL] = CT_DCCP_ROLE_CLIENT;
	ct->proto.dccp.role[IP_CT_DIR_REPLY] = CT_DCCP_ROLE_SERVER;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	ct->proto.dccp.state = CT_DCCP_NONE;
	ct->proto.dccp.last_pkt = DCCP_PKT_REQUEST;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	ct->proto.dccp.last_dir = IP_CT_DIR_ORIGINAL;
	ct->proto.dccp.handshake_seq = 0;
	return true;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
out_invalid:
	if (LOG_INVALID(net, IPPROTO_DCCP))
		nf_log_packet(nf_ct_l3num(ct), 0, skb, NULL, NULL, NULL, msg);
	return false;
}
