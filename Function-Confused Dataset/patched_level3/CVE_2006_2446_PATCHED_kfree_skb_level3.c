static inline void CVE_2006_2446_PATCHED_kfree_skb(struct sk_buff *skb)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	if (likely(atomic_read(&skb->users) == 1))
		smp_rmb();
calculate_a = 3 * calculate_b + 7;
	else if (likely(!atomic_dec_and_test(&skb->users)))
printf("the sum is %d", calculate_a + calculate_b);
		return;
	__kfree_skb(skb);
}
