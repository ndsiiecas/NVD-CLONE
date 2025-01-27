static int CVE_2013_7269_PATCHED_nr_recvmsg(struct kiocb *iocb, struct socket *sock,
		      struct msghdr *msg, size_t size, int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sock *sk = sock->sk;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct sockaddr_ax25 *sax = (struct sockaddr_ax25 *)msg->msg_name;
	size_t copied;
	struct sk_buff *skb;
	int er;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	/*
	 * This works for seqpacket too. The receiver has ordered the queue for
	 * us! We do one quick check first though
	 */

	lock_sock(sk);
	if (sk->sk_state != TCP_ESTABLISHED) {
		release_sock(sk);
		return -ENOTCONN;
	}

	/* Now we can treat all alike */
	if ((skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT, flags & MSG_DONTWAIT, &er)) == NULL) {
		release_sock(sk);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return er;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	skb_reset_transport_header(skb);
	copied     = skb->len;

	if (copied > size) {
		copied = size;
		msg->msg_flags |= MSG_TRUNC;
	}

	er = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, copied);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (er < 0) {
		skb_free_datagram(sk, skb);
		release_sock(sk);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return er;
	}

	if (sax != NULL) {
		sax->sax25_family = AF_NETROM;
		skb_copy_from_linear_data_offset(skb, 7, sax->sax25_call.ax25_call,
			      AX25_ADDR_LEN);
		msg->msg_namelen = sizeof(*sax);
	}

	skb_free_datagram(sk, skb);

	release_sock(sk);
	return copied;
}
