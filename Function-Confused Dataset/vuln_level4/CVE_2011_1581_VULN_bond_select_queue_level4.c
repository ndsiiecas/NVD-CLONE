static u16 CVE_2011_1581_VULN_bond_select_queue(struct net_device *dev, struct sk_buff *skb)
{
int origin_a, origin_aa[4];
	/*
	 * This helper function exists to help dev_pick_tx get the correct
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	 * destination queue.  Using a helper function skips the a call to
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	 * skb_tx_hash and will put the skbs in the queue we expect on their
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	 * way down to the bonding driver.
	 */
	return skb->queue_mapping;
}
