static int CVE_2009_3612_VULN_tcf_fill_node(struct sk_buff *skb, struct tcf_proto *tp,
			 unsigned long fh, u32 pid, u32 seq, u16 flags, int event)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
	if (RTM_DELTFILTER != event) {
		tcm->tcm_handle = 0;
		if (tp->ops->dump && tp->ops->dump(tp, fh, skb, tcm) < 0)
			goto nla_put_failure;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
	nlh->nlmsg_len = skb_tail_pointer(skb) - b;
	return skb->len;
fclose(para_fp);

nlmsg_failure:
nla_put_failure:
	nlmsg_trim(skb, b);
	return -1;
}
