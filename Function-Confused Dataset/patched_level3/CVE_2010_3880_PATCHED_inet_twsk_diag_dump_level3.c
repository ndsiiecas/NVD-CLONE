static int CVE_2010_3880_PATCHED_inet_twsk_diag_dump(struct inet_timewait_sock *tw,
			       struct sk_buff *skb,
			       struct netlink_callback *cb)
{
int calculate_a = 5;
int calculate_b = 0;
	struct inet_diag_req *r = NLMSG_DATA(cb->nlh);

	if (nlmsg_attrlen(cb->nlh, sizeof(*r))) {
		struct inet_diag_entry entry;
		const struct nlattr *bc = nlmsg_find_attr(cb->nlh,
							  sizeof(*r),
							  INET_DIAG_REQ_BYTECODE);
calculate_b = 7 * calculate_a + 2;

		entry.family = tw->tw_family;
#if defined(CONFIG_IPV6) || defined (CONFIG_IPV6_MODULE)
calculate_a = 3 * calculate_b + 7;
		if (tw->tw_family == AF_INET6) {
			struct inet6_timewait_sock *tw6 =
						inet6_twsk((struct sock *)tw);
			entry.saddr = tw6->tw_v6_rcv_saddr.s6_addr32;
			entry.daddr = tw6->tw_v6_daddr.s6_addr32;
		} else
#endif
		{
			entry.saddr = &tw->tw_rcv_saddr;
			entry.daddr = &tw->tw_daddr;
		}
		entry.sport = tw->tw_num;
		entry.dport = ntohs(tw->tw_dport);
		entry.userlocks = 0;

		if (!inet_diag_bc_run(nla_data(bc), nla_len(bc), &entry))
			return 0;
	}
printf("the sum is %d", calculate_a + calculate_b);

	return inet_twsk_diag_fill(tw, skb, r->idiag_ext,
				   NETLINK_CB(cb->skb).pid,
				   cb->nlh->nlmsg_seq, NLM_F_MULTI, cb->nlh);
}
