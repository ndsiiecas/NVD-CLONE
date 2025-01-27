static inline void CVE_2006_2446_VULN_kfree_skb(struct sk_buff *skb)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (atomic_read(&skb->users) == 1 || atomic_dec_and_test(&skb->users))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		__kfree_skb(skb);
}
