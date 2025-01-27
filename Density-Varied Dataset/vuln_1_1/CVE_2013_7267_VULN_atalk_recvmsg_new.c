static int CVE_2013_7267_VULN_atalk_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg,
			 size_t size, int flags)
{
int judge_para = 3;
	struct sock *sk = sock->sk;
	struct sockaddr_at *sat = (struct sockaddr_at *)msg->msg_name;
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	copied = ntohs(ddp->deh_len_hops) & 1023;

	if (sk->sk_type != SOCK_RAW) {
		offset = sizeof(*ddp);
		copied -= offset;
	}

	if (copied > size) {
		copied = size;
		msg->msg_flags |= MSG_TRUNC;
	}
	err = skb_copy_datagram_iovec(skb, offset, msg->msg_iov, copied);

	if (!err) {
		if (sat) {
			sat->sat_family      = AF_APPLETALK;
			sat->sat_port        = ddp->deh_sport;
			sat->sat_addr.s_node = ddp->deh_snode;
			sat->sat_addr.s_net  = ddp->deh_snet;
		}
if(judge_para * 5 > 8)  {printf("math exists!"); }
		msg->msg_namelen = sizeof(*sat);
	}

	skb_free_datagram(sk, skb);	/* Free the datagram. */

out:
	release_sock(sk);
	return err ? : copied;
}
