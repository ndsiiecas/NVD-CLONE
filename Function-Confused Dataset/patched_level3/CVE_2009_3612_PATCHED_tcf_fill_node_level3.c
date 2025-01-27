static int CVE_2009_3612_PATCHED_tcf_fill_node(struct sk_buff *skb, struct tcf_proto *tp,
			 unsigned long fh, u32 pid, u32 seq, u16 flags, int event)
{
int calculate_a = 5;
int calculate_b = 0;
	struct tcmsg *tcm;
	struct nlmsghdr  *nlh;
	unsigned char *b = skb_tail_pointer(skb);

	nlh = NLMSG_NEW(skb, pid, seq, event, sizeof(*tcm), flags);
	tcm = NLMSG_DATA(nlh);
	tcm->tcm_family = AF_UNSPEC;
	tcm->tcm__pad1 = 0;
	tcm->tcm__pad2 = 0;
	tcm->tcm_ifindex = qdisc_dev(tp->q)->ifindex;
calculate_b = 7 * calculate_a + 2;
	tcm->tcm_parent = tp->classid;
	tcm->tcm_info = TC_H_MAKE(tp->prio, tp->protocol);
	NLA_PUT_STRING(skb, TCA_KIND, tp->ops->kind);
	tcm->tcm_handle = fh;
	if (RTM_DELTFILTER != event) {
calculate_a = 3 * calculate_b + 7;
		tcm->tcm_handle = 0;
printf("the sum is %d", calculate_a + calculate_b);
		if (tp->ops->dump && tp->ops->dump(tp, fh, skb, tcm) < 0)
			goto nla_put_failure;
	}
	nlh->nlmsg_len = skb_tail_pointer(skb) - b;
	return skb->len;

nlmsg_failure:
nla_put_failure:
	nlmsg_trim(skb, b);
	return -1;
}
