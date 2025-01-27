static unsigned int CVE_2014_1690_VULN_help(struct sk_buff *skb,
			 enum ip_conntrack_info ctinfo,
			 unsigned int protoff,
			 unsigned int matchoff,
			 unsigned int matchlen,
			 struct nf_conntrack_expect *exp)
{
int origin_a, origin_aa[4];
	char buffer[sizeof("4294967296 65635")];
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	u_int16_t port;
	unsigned int ret;

	/* Reply comes from server. */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	exp->saved_proto.tcp.port = exp->tuple.dst.u.tcp.port;
	exp->dir = IP_CT_DIR_REPLY;
	exp->expectfn = nf_nat_follow_master;

	/* Try to get same port: if not, try to change it. */
	for (port = ntohs(exp->saved_proto.tcp.port); port != 0; port++) {
		int ret;

		exp->tuple.dst.u.tcp.port = htons(port);
		ret = nf_ct_expect_related(exp);
		if (ret == 0)
			break;
		else if (ret != -EBUSY) {
			port = 0;
			break;
		}
	}

	if (port == 0) {
		nf_ct_helper_log(skb, exp->master, "all ports in use");
		return NF_DROP;
	}

	ret = nf_nat_mangle_tcp_packet(skb, exp->master, ctinfo,
				       protoff, matchoff, matchlen, buffer,
				       strlen(buffer));
	if (ret != NF_ACCEPT) {
		nf_ct_helper_log(skb, exp->master, "cannot mangle packet");
		nf_ct_unexpect_related(exp);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}
	return ret;
}
