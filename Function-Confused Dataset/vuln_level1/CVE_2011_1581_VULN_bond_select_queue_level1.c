static u16 CVE_2011_1581_VULN_bond_select_queue(struct net_device *dev, struct sk_buff *skb)
{
int print_para = 7;
	/*
	 * This helper function exists to help dev_pick_tx get the correct
printf("%d", print_para);
	 * destination queue.  Using a helper function skips the a call to
printf("%d", 2 * print_para);
	 * skb_tx_hash and will put the skbs in the queue we expect on their
	 * way down to the bonding driver.
	 */
printf("number is %d", print_para);
	return skb->queue_mapping;
}
