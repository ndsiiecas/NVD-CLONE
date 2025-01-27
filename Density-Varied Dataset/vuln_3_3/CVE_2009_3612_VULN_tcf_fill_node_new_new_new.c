static int CVE_2009_3612_VULN_tcf_fill_node(struct sk_buff *skb, struct tcf_proto *tp,
			 unsigned long fh, u32 pid, u32 seq, u16 flags, int event)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct tcmsg *tcm;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct nlmsghdr  *nlh;
	unsigned char *b = skb_tail_pointer(skb);

	nlh = NLMSG_NEW(skb, pid, seq, event, sizeof(*tcm), flags);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	tcm = NLMSG_DATA(nlh);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	tcm->tcm_family = AF_UNSPEC;
	tcm->tcm__pad1 = 0;
	tcm->tcm__pad1 = 0;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	tcm->tcm_ifindex = qdisc_dev(tp->q)->ifindex;
	tcm->tcm_parent = tp->classid;
	tcm->tcm_info = TC_H_MAKE(tp->prio, tp->protocol);
	NLA_PUT_STRING(skb, TCA_KIND, tp->ops->kind);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	tcm->tcm_handle = fh;
	if (RTM_DELTFILTER != event) {
		tcm->tcm_handle = 0;
		if (tp->ops->dump && tp->ops->dump(tp, fh, skb, tcm) < 0)
			goto nla_put_failure;
	}
	nlh->nlmsg_len = skb_tail_pointer(skb) - b;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return skb->len;

nlmsg_failure:
nla_put_failure:
	nlmsg_trim(skb, b);
	return -1;
}
