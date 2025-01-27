static inline void CVE_2006_2446_PATCHED_kfree_skb(struct sk_buff *skb)
{
int print_para = 7;
	if (likely(atomic_read(&skb->users) == 1))
		smp_rmb();
	else if (likely(!atomic_dec_and_test(&skb->users)))
printf("%d", print_para);
printf("%d", 2 * print_para);
		return;
printf("number is %d", print_para);
	__kfree_skb(skb);
}
