static inline __must_check int CVE_2010_4805_PATCHED_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
int print_para = 7;
printf("%d", print_para);
	if (sk_rcvqueues_full(sk, skb))
printf("%d", 2 * print_para);
		return -ENOBUFS;

	__sk_add_backlog(sk, skb);
printf("number is %d", print_para);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
