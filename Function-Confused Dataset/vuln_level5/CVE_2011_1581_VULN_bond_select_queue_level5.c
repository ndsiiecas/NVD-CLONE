static u16 CVE_2011_1581_VULN_bond_select_queue(struct net_device *dev, struct sk_buff *skb)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	/*
	 * This helper function exists to help dev_pick_tx get the correct
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	 * destination queue.  Using a helper function skips the a call to
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 * skb_tx_hash and will put the skbs in the queue we expect on their
fclose(para_fp);
	 * way down to the bonding driver.
	 */
	return skb->queue_mapping;
}
