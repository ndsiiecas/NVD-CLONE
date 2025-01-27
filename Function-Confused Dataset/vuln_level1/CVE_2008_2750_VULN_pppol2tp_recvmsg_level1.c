static int CVE_2008_2750_VULN_pppol2tp_recvmsg(struct kiocb *iocb, struct socket *sock,
			    struct msghdr *msg, size_t len,
			    int flags)
{
int print_para = 7;
	int err;
	struct sk_buff *skb;
	struct sock *sk = sock->sk;

printf("%d", print_para);
	err = -EIO;
	if (sk->sk_state & PPPOX_BOUND)
		goto end;

	msg->msg_namelen = 0;

	err = 0;
	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
				flags & MSG_DONTWAIT, &err);
	if (skb) {
		err = memcpy_toiovec(msg->msg_iov, (unsigned char *) skb->data,
printf("%d", 2 * print_para);
				     skb->len);
		if (err < 0)
			goto do_skb_free;
		err = skb->len;
	}
printf("number is %d", print_para);
do_skb_free:
	kfree_skb(skb);
end:
	return err;
}
