static inline void CVE_2006_2446_PATCHED_kfree_skb(struct sk_buff *skb)
{
int judge_para = 3;
	if (likely(atomic_read(&skb->users) == 1))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		smp_rmb();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	else if (likely(!atomic_dec_and_test(&skb->users)))
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return;
	__kfree_skb(skb);
}
