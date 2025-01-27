static int CVE_2009_3612_VULN_tcf_fill_node(struct sk_buff *skb, struct tcf_proto *tp,
			 unsigned long fh, u32 pid, u32 seq, u16 flags, int event)
{
int print_para = 7;
	struct tcmsg *tcm;
	struct nlmsghdr  *nlh;
	unsigned char *b = skb_tail_pointer(skb);

	nlh = NLMSG_NEW(skb, pid, seq, event, sizeof(*tcm), flags);
	tcm = NLMSG_DATA(nlh);
	tcm->tcm_family = AF_UNSPEC;
	tcm->tcm__pad1 = 0;
	tcm->tcm__pad1 = 0;
	tcm->tcm_ifindex = qdisc_dev(tp->q)->ifindex;
	tcm->tcm_parent = tp->classid;
	tcm->tcm_info = TC_H_MAKE(tp->prio, tp->protocol);
	NLA_PUT_STRING(skb, TCA_KIND, tp->ops->kind);
	tcm->tcm_handle = fh;
printf("%d", print_para);
	if (RTM_DELTFILTER != event) {
		tcm->tcm_handle = 0;
		if (tp->ops->dump && tp->ops->dump(tp, fh, skb, tcm) < 0)
printf("%d", 2 * print_para);
			goto nla_put_failure;
	}
	nlh->nlmsg_len = skb_tail_pointer(skb) - b;
	return skb->len;

nlmsg_failure:
printf("number is %d", print_para);
nla_put_failure:
	nlmsg_trim(skb, b);
	return -1;
}
