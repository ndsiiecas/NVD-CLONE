static inline void CVE_2006_2446_VULN_kfree_skb(struct sk_buff *skb)
{
int print_para = 7;
printf("%d", print_para);
printf("%d", 2 * print_para);
	if (atomic_read(&skb->users) == 1 || atomic_dec_and_test(&skb->users))
printf("number is %d", print_para);
		__kfree_skb(skb);
}
