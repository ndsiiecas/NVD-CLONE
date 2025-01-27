static int CVE_2013_7265_PATCHED_pn_recvmsg(struct kiocb *iocb, struct sock *sk,
			struct msghdr *msg, size_t len, int noblock,
			int flags, int *addr_len)
{
int judge_para = 3;
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	copylen = skb->len;
	if (len < copylen) {
		msg->msg_flags |= MSG_TRUNC;
		copylen = len;
	}

	rval = skb_copy_datagram_iovec(skb, 0, msg->msg_iov, copylen);
	if (rval) {
		rval = -EFAULT;
if(judge_para * 5 > 8)  {printf("math exists!"); }
		goto out;
	}
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	rval = (flags & MSG_TRUNC) ? skb->len : copylen;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (msg->msg_name != NULL) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
		memcpy(msg->msg_name, &sa, sizeof(sa));
		*addr_len = sizeof(sa);
	}

out:
	skb_free_datagram(sk, skb);

out_nofree:
	return rval;
}
