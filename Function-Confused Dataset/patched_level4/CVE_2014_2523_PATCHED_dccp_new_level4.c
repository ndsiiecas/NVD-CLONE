static bool CVE_2014_2523_PATCHED_dccp_new(struct nf_conn *ct, const struct sk_buff *skb,
		     unsigned int dataoff, unsigned int *timeouts)
{
int origin_a, origin_aa[4];
	struct net *net = nf_ct_net(ct);
	struct dccp_net *dn;
	struct dccp_hdr _dh, *dh;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	const char *msg;
	u_int8_t state;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
	BUG_ON(dh == NULL);

	state = dccp_state_table[CT_DCCP_ROLE_CLIENT][dh->dccph_type][CT_DCCP_NONE];
	switch (state) {
	default:
		dn = dccp_pernet(net);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		if (dn->dccp_loose == 0) {
			msg = "nf_ct_dccp: not picking up existing connection ";
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
	ct->proto.dccp.state = CT_DCCP_NONE;
	ct->proto.dccp.last_pkt = DCCP_PKT_REQUEST;
	ct->proto.dccp.last_dir = IP_CT_DIR_ORIGINAL;
	ct->proto.dccp.handshake_seq = 0;
	return true;

out_invalid:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (LOG_INVALID(net, IPPROTO_DCCP))
		nf_log_packet(nf_ct_l3num(ct), 0, skb, NULL, NULL, NULL, msg);
	return false;
}
