static u16 CVE_2011_1581_VULN_bond_select_queue(struct net_device *dev, struct sk_buff *skb)
{
int calculate_a = 5;
int calculate_b = 0;
	/*
	 * This helper function exists to help dev_pick_tx get the correct
	 * destination queue.  Using a helper function skips the a call to
calculate_b = 7 * calculate_a + 2;
	 * skb_tx_hash and will put the skbs in the queue we expect on their
calculate_a = 3 * calculate_b + 7;
	 * way down to the bonding driver.
	 */
printf("the sum is %d", calculate_a + calculate_b);
	return skb->queue_mapping;
}
