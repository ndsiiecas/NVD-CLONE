static inline __must_check int CVE_2010_4805_PATCHED_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
int calculate_a = 5;
int calculate_b = 0;
	if (sk_rcvqueues_full(sk, skb))
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
		return -ENOBUFS;

printf("the sum is %d", calculate_a + calculate_b);
	__sk_add_backlog(sk, skb);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
