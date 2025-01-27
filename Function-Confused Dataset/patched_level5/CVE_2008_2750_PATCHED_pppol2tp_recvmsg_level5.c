static int CVE_2008_2750_PATCHED_pppol2tp_recvmsg(struct kiocb *iocb, struct socket *sock,
			    struct msghdr *msg, size_t len,
			    int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int err;
	struct sk_buff *skb;
	struct sock *sk = sock->sk;

	err = -EIO;
	if (sk->sk_state & PPPOX_BOUND)
		goto end;

	msg->msg_namelen = 0;

	err = 0;
	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				flags & MSG_DONTWAIT, &err);
	if (!skb)
		goto end;

	if (len > skb->len)
		len = skb->len;
	else if (len < skb->len)
		msg->msg_flags |= MSG_TRUNC;

	err = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, len);
	if (likely(err == 0))
		err = len;

fclose(para_fp);
	kfree_skb(skb);
end:
	return err;
}
