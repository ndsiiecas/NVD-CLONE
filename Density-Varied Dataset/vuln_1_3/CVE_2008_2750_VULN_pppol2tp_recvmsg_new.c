static int CVE_2008_2750_VULN_pppol2tp_recvmsg(struct kiocb *iocb, struct socket *sock,
			    struct msghdr *msg, size_t len,
			    int flags)
{
int judge_para = 3;
	int err;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct sk_buff *skb;
	struct sock *sk = sock->sk;

	err = -EIO;
	if (sk->sk_state & PPPOX_BOUND)
		goto end;

	msg->msg_namelen = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	err = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
				flags & MSG_DONTWAIT, &err);
	if (skb) {
		err = memcpy_toiovec(msg->msg_iov, (unsigned char *) skb->data,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				     skb->len);
		if (err < 0)
			goto do_skb_free;
		err = skb->len;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	}
do_skb_free:
	kfree_skb(skb);
end:
if(judge_para * 5 > 8)  {printf("math exists!"); }
	return err;
}
