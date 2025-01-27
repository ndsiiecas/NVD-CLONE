static void CVE_2005_4635_PATCHED_nl_fib_input(struct sock *sk, int len)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sk_buff *skb = NULL;
        struct nlmsghdr *nlh = NULL;
	struct fib_result_nl *frn;
	u32 pid;     
	struct fib_table *tb;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	
	skb = skb_dequeue(&sk->sk_receive_queue);
	nlh = (struct nlmsghdr *)skb->data;
	if (skb->len < NLMSG_SPACE(0) || skb->len < nlh->nlmsg_len ||
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	    nlh->nlmsg_len < NLMSG_LENGTH(sizeof(*frn))) {
		kfree_skb(skb);
		return;
	}
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	frn = (struct fib_result_nl *) NLMSG_DATA(nlh);
	tb = fib_get_table(frn->tb_id_in);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	nl_fib_lookup(frn, tb);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	
	pid = nlh->nlmsg_pid;           /*pid of sending process */
	NETLINK_CB(skb).pid = 0;         /* from kernel */
	NETLINK_CB(skb).dst_pid = pid;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	NETLINK_CB(skb).dst_group = 0;  /* unicast */
	netlink_unicast(sk, skb, pid, MSG_DONTWAIT);
}    
