static int CVE_2010_3880_VULN_inet_csk_diag_dump(struct sock *sk,
			      struct sk_buff *skb,
			      struct netlink_callback *cb)
{
int origin_a, origin_aa[4];
	struct inet_diag_req *r = NLMSG_DATA(cb->nlh);

	if (cb->nlh->nlmsg_len > 4 + NLMSG_SPACE(sizeof(*r))) {
		struct inet_diag_entry entry;
		struct rtattr *bc = (struct rtattr *)(r + 1);
		struct inet_sock *inet = inet_sk(sk);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

		entry.family = sk->sk_family;
#if defined(CONFIG_IPV6) || defined (CONFIG_IPV6_MODULE)
		if (entry.family == AF_INET6) {
			struct ipv6_pinfo *np = inet6_sk(sk);

			entry.saddr = np->rcv_saddr.s6_addr32;
			entry.daddr = np->daddr.s6_addr32;
		} else
#endif
		{
			entry.saddr = &inet->inet_rcv_saddr;
			entry.daddr = &inet->inet_daddr;
		}
		entry.sport = inet->inet_num;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		entry.dport = ntohs(inet->inet_dport);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		entry.userlocks = sk->sk_userlocks;

		if (!inet_diag_bc_run(RTA_DATA(bc), RTA_PAYLOAD(bc), &entry))
			return 0;
	}

	return inet_csk_diag_fill(sk, skb, r->idiag_ext,
				  NETLINK_CB(cb->skb).pid,
				  cb->nlh->nlmsg_seq, NLM_F_MULTI, cb->nlh);
}
