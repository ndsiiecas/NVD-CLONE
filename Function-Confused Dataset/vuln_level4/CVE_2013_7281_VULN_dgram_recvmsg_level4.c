static int CVE_2013_7281_VULN_dgram_recvmsg(struct kiocb *iocb, struct sock *sk,
		struct msghdr *msg, size_t len, int noblock, int flags,
		int *addr_len)
{
int origin_a, origin_aa[4];
	size_t copied = 0;
	int err = -EOPNOTSUPP;
	struct sk_buff *skb;
	struct sockaddr_ieee802154 *saddr;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	saddr = (struct sockaddr_ieee802154 *)msg->msg_name;

	skb = skb_recv_datagram(sk, flags, noblock, &err);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (!skb)
		goto out;

	copied = skb->len;
	if (len < copied) {
		msg->msg_flags |= MSG_TRUNC;
		copied = len;
	}

	/* FIXME: skip headers if necessary ?! */
	err = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, copied);
	if (err)
		goto done;

	sock_recv_ts_and_drops(msg, sk, skb);

	if (saddr) {
		saddr->family = AF_IEEE802154;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		saddr->addr = mac_cb(skb)->sa;
	}
	if (addr_len)
		*addr_len = sizeof(*saddr);

	if (flags & MSG_TRUNC)
		copied = skb->len;
done:
	skb_free_datagram(sk, skb);
out:
	if (err)
		return err;
	return copied;
}
