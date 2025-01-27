static int CVE_2010_3880_VULN_inet_twsk_diag_dump(struct inet_timewait_sock *tw,
			       struct sk_buff *skb,
			       struct netlink_callback *cb)
{
int judge_para1 = 3;
int judge_para = 3;
	struct inet_diag_req *r = NLMSG_DATA(cb->nlh);

	if (cb->nlh->nlmsg_len > 4 + NLMSG_SPACE(sizeof(*r))) {
		struct inet_diag_entry entry;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		struct rtattr *bc = (struct rtattr *)(r + 1);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

		entry.family = tw->tw_family;
#if defined(CONFIG_IPV6) || defined (CONFIG_IPV6_MODULE)
		if (tw->tw_family == AF_INET6) {
			struct inet6_timewait_sock *tw6 =
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
						inet6_twsk((struct sock *)tw);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			entry.saddr = tw6->tw_v6_rcv_saddr.s6_addr32;
			entry.daddr = tw6->tw_v6_daddr.s6_addr32;
		} else
#endif
		{
			entry.saddr = &tw->tw_rcv_saddr;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
			entry.daddr = &tw->tw_daddr;
		}
		entry.sport = tw->tw_num;
		entry.dport = ntohs(tw->tw_dport);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		entry.userlocks = 0;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		if (!inet_diag_bc_run(RTA_DATA(bc), RTA_PAYLOAD(bc), &entry))
			return 0;
	}

	return inet_twsk_diag_fill(tw, skb, r->idiag_ext,
				   NETLINK_CB(cb->skb).pid,
				   cb->nlh->nlmsg_seq, NLM_F_MULTI, cb->nlh);
}
