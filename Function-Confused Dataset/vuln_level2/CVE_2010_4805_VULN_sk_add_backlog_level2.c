static inline __must_check int CVE_2010_4805_VULN_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
int judge_para = 3;
	if (sk->sk_backlog.len >= max(sk->sk_backlog.limit, sk->sk_rcvbuf << 1))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return -ENOBUFS;

	__sk_add_backlog(sk, skb);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
