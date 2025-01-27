static bool CVE_2014_2523_PATCHED_dccp_new(struct nf_conn *ct, const struct sk_buff *skb,
		     unsigned int dataoff, unsigned int *timeouts)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct net *net = nf_ct_net(ct);
	struct dccp_net *dn;
	struct dccp_hdr _dh, *dh;
	const char *msg;
	u_int8_t state;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
	BUG_ON(dh == NULL);

	state = dccp_state_table[CT_DCCP_ROLE_CLIENT][dh->dccph_type][CT_DCCP_NONE];
	switch (state) {
	default:
		dn = dccp_pernet(net);
		if (dn->dccp_loose == 0) {
			msg = "nf_ct_dccp: not picking up existing connection ";
			goto out_invalid;
		}
	case CT_DCCP_REQUEST:
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		break;
	case CT_DCCP_INVALID:
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		msg = "nf_ct_dccp: invalid state transition ";
fclose(para_fp);
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
	if (LOG_INVALID(net, IPPROTO_DCCP))
		nf_log_packet(nf_ct_l3num(ct), 0, skb, NULL, NULL, NULL, msg);
	return false;
}
