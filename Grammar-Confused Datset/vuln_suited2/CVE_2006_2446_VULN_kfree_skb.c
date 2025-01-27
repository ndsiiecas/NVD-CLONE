static inline void CVE_2006_2446_VULN_kfree_skb(struct sk_buff *skb)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	if (atomic_read(&skb->users) == 1 || atomic_dec_and_test(&skb->users))
		__kfree_skb(skb);
}
