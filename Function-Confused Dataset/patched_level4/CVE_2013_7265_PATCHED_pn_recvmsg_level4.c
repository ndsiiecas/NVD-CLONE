static int CVE_2013_7265_PATCHED_pn_recvmsg(struct kiocb *iocb, struct sock *sk,
			struct msghdr *msg, size_t len, int noblock,
			int flags, int *addr_len)
{
int origin_a, origin_aa[4];
	struct sk_buff *skb = NULL;
	struct sockaddr_pn sa;
	int rval = -EOPNOTSUPP;
	int copylen;

	if (flags & ~(MSG_PEEK|MSG_TRUNC|MSG_DONTWAIT|MSG_NOSIGNAL|
			MSG_CMSG_COMPAT))
		goto out_nofree;

	skb = skb_recv_datagram(sk, flags, noblock, &rval);
	if (skb == NULL)
		goto out_nofree;

	pn_skb_get_src_sockaddr(skb, &sa);

	copylen = skb->len;
	if (len < copylen) {
		msg->msg_flags |= MSG_TRUNC;
		copylen = len;
	}

	rval = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, copylen);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	if (rval) {
		rval = -EFAULT;
		goto out;
	}

	rval = (flags & MSG_TRUNC) ? skb->len : copylen;

	if (msg->msg_name != NULL) {
		memcpy(msg->msg_name, &sa, sizeof(sa));
		*addr_len = sizeof(sa);
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}

out:
	skb_free_datagram(sk, skb);

out_nofree:
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return rval;
}
