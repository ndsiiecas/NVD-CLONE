static int CVE_2013_7267_PATCHED_atalk_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg,
			 size_t size, int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sock *sk = sock->sk;
	struct ddpehdr *ddp;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int copied = 0;
	int offset = 0;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int err = 0;
	struct sk_buff *skb;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
						flags & MSG_DONTWAIT, &err);
	lock_sock(sk);

	if (!skb)
		goto out;

	/* FIXME: use skb->cb to be able to use shared skbs */
	ddp = ddp_hdr(skb);
	copied = ntohs(ddp->deh_len_hops) & 1023;

	if (sk->sk_type != SOCK_RAW) {
		offset = sizeof(*ddp);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		copied -= offset;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	if (copied > size) {
		copied = size;
		msg->msg_flags |= MSG_TRUNC;
	}
	err = skb_copy_datagram_iovec(skb, offset, msg->msg_iov, copied);

	if (!err && msg->msg_name) {
		struct sockaddr_at *sat = msg->msg_name;
		sat->sat_family      = AF_APPLETALK;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		sat->sat_port        = ddp->deh_sport;
		sat->sat_addr.s_node = ddp->deh_snode;
		sat->sat_addr.s_net  = ddp->deh_snet;
		msg->msg_namelen     = sizeof(*sat);
	}

	skb_free_datagram(sk, skb);	/* Free the datagram. */

out:
	release_sock(sk);
	return err ? : copied;
}
