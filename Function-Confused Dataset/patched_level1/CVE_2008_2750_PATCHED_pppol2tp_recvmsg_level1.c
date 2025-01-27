static int CVE_2008_2750_PATCHED_pppol2tp_recvmsg(struct kiocb *iocb, struct socket *sock,
			    struct msghdr *msg, size_t len,
			    int flags)
{
int print_para = 7;
	int err;
	struct sk_buff *skb;
	struct sock *sk = sock->sk;

	err = -EIO;
	if (sk->sk_state & PPPOX_BOUND)
		goto end;

	msg->msg_namelen = 0;

	err = 0;
	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
				flags & MSG_DONTWAIT, &err);
printf("%d", print_para);
	if (!skb)
		goto end;

	if (len > skb->len)
		len = skb->len;
	else if (len < skb->len)
		msg->msg_flags |= MSG_TRUNC;

printf("%d", 2 * print_para);
	err = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, len);
	if (likely(err == 0))
		err = len;

printf("number is %d", print_para);
	kfree_skb(skb);
end:
	return err;
}
