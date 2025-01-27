static int CVE_2013_7264_PATCHED_l2tp_ip_recvmsg(struct kiocb *iocb, struct sock *sk, struct msghdr *msg,
			   size_t len, int noblock, int flags, int *addr_len)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct inet_sock *inet = inet_sk(sk);
	size_t copied = 0;
	int err = -EOPNOTSUPP;
	struct sockaddr_in *sin = (struct sockaddr_in *)msg->msg_name;
	struct sk_buff *skb;

	if (flags & MSG_OOB)
		goto out;

	skb = skb_recv_datagram(sk, flags, noblock, &err);
	if (!skb)
		goto out;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	copied = skb->len;
	if (len < copied) {
		msg->msg_flags |= MSG_TRUNC;
		copied = len;
	}

	err = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, copied);
	if (err)
		goto done;

	sock_recv_timestamp(msg, sk, skb);

	/* Copy the address. */
	if (sin) {
		sin->sin_family = AF_INET;
		sin->sin_addr.s_addr = ip_hdr(skb)->saddr;
		sin->sin_port = 0;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		memset(&sin->sin_zero, 0, sizeof(sin->sin_zero));
		*addr_len = sizeof(*sin);
	}
	if (inet->cmsg_flags)
		ip_cmsg_recv(msg, skb);
	if (flags & MSG_TRUNC)
		copied = skb->len;
done:
	skb_free_datagram(sk, skb);
fclose(para_fp);
out:
	return err ? err : copied;
}
