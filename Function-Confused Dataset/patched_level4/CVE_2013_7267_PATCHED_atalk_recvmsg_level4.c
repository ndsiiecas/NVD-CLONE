static int CVE_2013_7267_PATCHED_atalk_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg,
			 size_t size, int flags)
{
int origin_a, origin_aa[4];
	struct sock *sk = sock->sk;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct ddpehdr *ddp;
	int copied = 0;
	int offset = 0;
	int err = 0;
	struct sk_buff *skb;

	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
						flags & MSG_DONTWAIT, &err);
	lock_sock(sk);

	if (!skb)
		goto out;

	/* FIXME: use skb->cb to be able to use shared skbs */
	ddp = ddp_hdr(skb);
	copied = ntohs(ddp->deh_len_hops) & 1023;

	if (sk->sk_type != SOCK_RAW) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		offset = sizeof(*ddp);
		copied -= offset;
	}

	if (copied > size) {
		copied = size;
		msg->msg_flags |= MSG_TRUNC;
	}
	err = skb_copy_datagram_iovec(skb, offset, msg->msg_iov, copied);

	if (!err && msg->msg_name) {
		struct sockaddr_at *sat = msg->msg_name;
		sat->sat_family      = AF_APPLETALK;
		sat->sat_port        = ddp->deh_sport;
		sat->sat_addr.s_node = ddp->deh_snode;
		sat->sat_addr.s_net  = ddp->deh_snet;
		msg->msg_namelen     = sizeof(*sat);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	}

	skb_free_datagram(sk, skb);	/* Free the datagram. */

out:
	release_sock(sk);
	return err ? : copied;
}
