static void CVE_2005_4635_VULN_nl_fib_input(struct sock *sk, int len)
{
int origin_a, origin_aa[4];
	struct sk_buff *skb = NULL;
        struct nlmsghdr *nlh = NULL;
	struct fib_result_nl *frn;
	int err;
	u32 pid;     
	struct fib_table *tb;
	
	skb = skb_recv_datagram(sk, 0, 0, &err);
	nlh = (struct nlmsghdr *)skb->data;
	
	frn = (struct fib_result_nl *) NLMSG_DATA(nlh);
	tb = fib_get_table(frn->tb_id_in);

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	nl_fib_lookup(frn, tb);
	
	pid = nlh->nlmsg_pid;           /*pid of sending process */
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	NETLINK_CB(skb).pid = 0;         /* from kernel */
	NETLINK_CB(skb).dst_pid = pid;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	NETLINK_CB(skb).dst_group = 0;  /* unicast */
	netlink_unicast(sk, skb, pid, MSG_DONTWAIT);
}    
