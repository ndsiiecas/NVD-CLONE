static void CVE_2005_4635_VULN_nl_fib_input(struct sock *sk, int len)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct sk_buff *skb = NULL;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        struct nlmsghdr *nlh = NULL;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	struct fib_result_nl *frn;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int err;
	u32 pid;     
	struct fib_table *tb;
	
	skb = skb_recv_datagram(sk, 0, 0, &err);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	nlh = (struct nlmsghdr *)skb->data;
	
	frn = (struct fib_result_nl *) NLMSG_DATA(nlh);
	tb = fib_get_table(frn->tb_id_in);

	nl_fib_lookup(frn, tb);
	
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	pid = nlh->nlmsg_pid;           /*pid of sending process */
	NETLINK_CB(skb).pid = 0;         /* from kernel */
	NETLINK_CB(skb).dst_pid = pid;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	NETLINK_CB(skb).dst_group = 0;  /* unicast */
	netlink_unicast(sk, skb, pid, MSG_DONTWAIT);
}    
