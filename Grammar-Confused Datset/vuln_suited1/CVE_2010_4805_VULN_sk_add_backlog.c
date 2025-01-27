static inline __must_check int CVE_2010_4805_VULN_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
	if (sk->sk_backlog.len >= max(sk->sk_backlog.limit, sk->sk_rcvbuf << 1))
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return -ENOBUFS;

	__sk_add_backlog(sk, skb);
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
