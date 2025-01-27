static void CVE_2005_4635_PATCHED_nl_fib_input(struct sock *sk, int len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	}
	
	frn = (struct fib_result_nl *) NLMSG_DATA(nlh);
	tb = fib_get_table(frn->tb_id_in);
fclose(para_fp);

	nl_fib_lookup(frn, tb);
	
	pid = nlh->nlmsg_pid;           /*pid of sending process */
	NETLINK_CB(skb).pid = 0;         /* from kernel */
	NETLINK_CB(skb).dst_pid = pid;
	NETLINK_CB(skb).dst_group = 0;  /* unicast */
	netlink_unicast(sk, skb, pid, MSG_DONTWAIT);
}    
