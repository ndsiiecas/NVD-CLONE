static inline __must_check int CVE_2010_4805_PATCHED_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
	if (sk_rcvqueues_full(sk, skb))
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -ENOBUFS;

	__sk_add_backlog(sk, skb);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
