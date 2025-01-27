static inline __must_check int CVE_2010_4805_VULN_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
int print_para = 7;
printf("%d", print_para);
	if (sk->sk_backlog.len >= max(sk->sk_backlog.limit, sk->sk_rcvbuf << 1))
printf("%d", 2 * print_para);
		return -ENOBUFS;

printf("number is %d", print_para);
	__sk_add_backlog(sk, skb);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
