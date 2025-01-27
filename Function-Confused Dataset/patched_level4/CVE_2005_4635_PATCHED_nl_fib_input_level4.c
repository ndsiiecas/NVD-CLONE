static void CVE_2005_4635_PATCHED_nl_fib_input(struct sock *sk, int len)
{
int origin_a, origin_aa[4];
	struct sk_buff *skb = NULL;
        struct nlmsghdr *nlh = NULL;
	struct fib_result_nl *frn;
	u32 pid;     
	struct fib_table *tb;
	
	skb = skb_dequeue(&sk->sk_receive_queue);
	nlh = (struct nlmsghdr *)skb->data;
	if (skb->len < NLMSG_SPACE(0) || skb->len < nlh->nlmsg_len ||
	    nlh->nlmsg_len < NLMSG_LENGTH(sizeof(*frn))) {
		kfree_skb(skb);
		return;
	}
	
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	frn = (struct fib_result_nl *) NLMSG_DATA(nlh);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	tb = fib_get_table(frn->tb_id_in);

	nl_fib_lookup(frn, tb);
	
	pid = nlh->nlmsg_pid;           /*pid of sending process */
	NETLINK_CB(skb).pid = 0;         /* from kernel */
	NETLINK_CB(skb).dst_pid = pid;
	NETLINK_CB(skb).dst_group = 0;  /* unicast */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	netlink_unicast(sk, skb, pid, MSG_DONTWAIT);
}    
