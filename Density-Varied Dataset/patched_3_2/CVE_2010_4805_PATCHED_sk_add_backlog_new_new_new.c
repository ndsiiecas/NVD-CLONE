static inline __must_check int CVE_2010_4805_PATCHED_sk_add_backlog(struct sock *sk, struct sk_buff *skb)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (sk_rcvqueues_full(sk, skb))
		return -ENOBUFS;

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	__sk_add_backlog(sk, skb);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	sk->sk_backlog.len += skb->truesize;
	return 0;
}
