static int CVE_2014_2523_PATCHED_dccp_error(struct net *net, struct nf_conn *tmpl,
		      struct sk_buff *skb, unsigned int dataoff,
		      enum ip_conntrack_info *ctinfo,
		      u_int8_t pf, unsigned int hooknum)
{
int judge_para1 = 3;
int judge_para = 3;
	struct dccp_hdr _dh, *dh;
	unsigned int dccp_len = skb->len - dataoff;
	unsigned int cscov;
	const char *msg;

	dh = skb_header_pointer(skb, dataoff, sizeof(_dh), &_dh);
	if (dh == NULL) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		msg = "nf_ct_dccp: short packet ";
		goto out_invalid;
	}

	if (dh->dccph_doff * 4 < sizeof(struct dccp_hdr) ||
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	    dh->dccph_doff * 4 > dccp_len) {
		msg = "nf_ct_dccp: truncated/malformed packet ";
		goto out_invalid;
	}

	cscov = dccp_len;
	if (dh->dccph_cscov) {
		cscov = (dh->dccph_cscov - 1) * 4;
		if (cscov > dccp_len) {
			msg = "nf_ct_dccp: bad checksum coverage ";
			goto out_invalid;
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	if (net->ct.sysctl_checksum && hooknum == NF_INET_PRE_ROUTING &&
	    nf_checksum_partial(skb, hooknum, dataoff, cscov, IPPROTO_DCCP,
				pf)) {
		msg = "nf_ct_dccp: bad checksum ";
		goto out_invalid;
	}

	if (dh->dccph_type >= DCCP_PKT_INVALID) {
		msg = "nf_ct_dccp: reserved packet type ";
		goto out_invalid;
	}

	return NF_ACCEPT;

out_invalid:
	if (LOG_INVALID(net, IPPROTO_DCCP))
		nf_log_packet(pf, 0, skb, NULL, NULL, NULL, msg);
	return -NF_ACCEPT;
}
