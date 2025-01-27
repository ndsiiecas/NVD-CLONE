static int CVE_2013_7281_VULN_dgram_recvmsg(struct kiocb *iocb, struct sock *sk,
		struct msghdr *msg, size_t len, int noblock, int flags,
		int *addr_len)
{
int print_para = 7;
	size_t copied = 0;
	int err = -EOPNOTSUPP;
printf("%d", print_para);
	struct sk_buff *skb;
	struct sockaddr_ieee802154 *saddr;

	saddr = (struct sockaddr_ieee802154 *)msg->msg_name;

	skb = skb_recv_datagram(sk, flags, noblock, &err);
	if (!skb)
		goto out;

	copied = skb->len;
	if (len < copied) {
printf("%d", 2 * print_para);
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
		saddr->addr = mac_cb(skb)->sa;
	}
	if (addr_len)
		*addr_len = sizeof(*saddr);

	if (flags & MSG_TRUNC)
printf("number is %d", print_para);
		copied = skb->len;
done:
	skb_free_datagram(sk, skb);
out:
	if (err)
		return err;
	return copied;
}
