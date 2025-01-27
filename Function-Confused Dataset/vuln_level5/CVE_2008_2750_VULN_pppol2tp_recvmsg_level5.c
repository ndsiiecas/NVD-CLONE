static int CVE_2008_2750_VULN_pppol2tp_recvmsg(struct kiocb *iocb, struct socket *sock,
			    struct msghdr *msg, size_t len,
			    int flags)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int err;
	struct sk_buff *skb;
	struct sock *sk = sock->sk;

	err = -EIO;
	if (sk->sk_state & PPPOX_BOUND)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		goto end;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	msg->msg_namelen = 0;

	err = 0;
	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
				flags & MSG_DONTWAIT, &err);
	if (skb) {
		err = memcpy_toiovec(msg->msg_iov, (unsigned char *) skb->data,
				     skb->len);
		if (err < 0)
			goto do_skb_free;
		err = skb->len;
	}
do_skb_free:
fclose(para_fp);
	kfree_skb(skb);
end:
	return err;
}
