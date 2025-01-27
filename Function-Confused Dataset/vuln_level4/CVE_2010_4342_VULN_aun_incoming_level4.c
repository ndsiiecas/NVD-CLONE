static void CVE_2010_4342_VULN_aun_incoming(struct sk_buff *skb, struct aunhdr *ah, size_t len)
{
int origin_a, origin_aa[4];
	struct iphdr *ip = ip_hdr(skb);
	unsigned char stn = ntohl(ip->saddr) & 0xff;
	struct sock *sk = NULL;
	struct sk_buff *newskb;
	struct ec_device *edev = skb->dev->ec_ptr;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	if (! edev)
		goto bad;

	if ((sk = ec_listening_socket(ah->port, stn, edev->net)) == NULL)
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		goto bad;		/* Nobody wants it */

	newskb = alloc_skb((len - sizeof(struct aunhdr) + 15) & ~15,
			   GFP_ATOMIC);
	if (newskb == NULL)
	{
		printk(KERN_DEBUG "AUN: memory squeeze, dropping packet.\n");
		/* Send nack and hope sender tries again */
		goto bad;
	}

	memcpy(skb_put(newskb, len - sizeof(struct aunhdr)), (void *)(ah+1),
	       len - sizeof(struct aunhdr));

	if (ec_queue_packet(sk, newskb, stn, edev->net, ah->cb, ah->port))
	{
		/* Socket is bankrupt. */
		kfree_skb(newskb);
		goto bad;
	}

	aun_send_response(ip->saddr, ah->handle, 3, 0);
	sock_put(sk);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return;

bad:
	aun_send_response(ip->saddr, ah->handle, 4, 0);
	if (sk)
		sock_put(sk);
}
