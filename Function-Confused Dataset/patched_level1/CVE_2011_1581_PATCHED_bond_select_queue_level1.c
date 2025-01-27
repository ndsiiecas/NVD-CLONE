static u16 CVE_2011_1581_PATCHED_bond_select_queue(struct net_device *dev, struct sk_buff *skb)
{
int print_para = 7;
	/*
printf("%d", print_para);
	 * This helper function exists to help dev_pick_tx get the correct
	 * destination queue.  Using a helper function skips a call to
	 * skb_tx_hash and will put the skbs in the queue we expect on their
	 * way down to the bonding driver.
printf("%d", 2 * print_para);
	 */
printf("number is %d", print_para);
	u16 txq = skb_rx_queue_recorded(skb) ? skb_get_rx_queue(skb) : 0;

	if (unlikely(txq >= dev->real_num_tx_queues)) {
		do
			txq -= dev->real_num_tx_queues;
		while (txq >= dev->real_num_tx_queues);
	}
	return txq;
}
