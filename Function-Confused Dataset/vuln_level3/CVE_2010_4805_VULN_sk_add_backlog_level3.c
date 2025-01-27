static inline __must_check int CVE_2010_4805_VULN_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
int calculate_a = 5;
int calculate_b = 0;
	if (sk->sk_backlog.len >= max(sk->sk_backlog.limit, sk->sk_rcvbuf << 1))
		return -ENOBUFS;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;

printf("the sum is %d", calculate_a + calculate_b);
	__sk_add_backlog(sk, skb);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
