static int CVE_2010_3880_VULN_inet_csk_diag_dump(struct sock *sk,
			      struct sk_buff *skb,
			      struct netlink_callback *cb)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct inet_diag_req *r = NLMSG_DATA(cb->nlh);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	if (cb->nlh->nlmsg_len > 4 + NLMSG_SPACE(sizeof(*r))) {
		struct inet_diag_entry entry;
		struct rtattr *bc = (struct rtattr *)(r + 1);
		struct inet_sock *inet = inet_sk(sk);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

		entry.family = sk->sk_family;
#if defined(CONFIG_IPV6) || defined (CONFIG_IPV6_MODULE)
		if (entry.family == AF_INET6) {
			struct ipv6_pinfo *np = inet6_sk(sk);

			entry.saddr = np->rcv_saddr.s6_addr32;
			entry.daddr = np->daddr.s6_addr32;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		} else
#endif
		{
			entry.saddr = &inet->inet_rcv_saddr;
			entry.daddr = &inet->inet_daddr;
		}
		entry.sport = inet->inet_num;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		entry.dport = ntohs(inet->inet_dport);
		entry.userlocks = sk->sk_userlocks;

		if (!inet_diag_bc_run(RTA_DATA(bc), RTA_PAYLOAD(bc), &entry))
			return 0;
	}

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	return inet_csk_diag_fill(sk, skb, r->idiag_ext,
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
				  NETLINK_CB(cb->skb).pid,
				  cb->nlh->nlmsg_seq, NLM_F_MULTI, cb->nlh);
}
