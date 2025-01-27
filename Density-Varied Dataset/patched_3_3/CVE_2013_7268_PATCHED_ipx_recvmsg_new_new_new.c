static int CVE_2013_7268_PATCHED_ipx_recvmsg(struct kiocb *iocb, struct socket *sock,
		struct msghdr *msg, size_t size, int flags)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sock *sk = sock->sk;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct ipx_sock *ipxs = ipx_sk(sk);
	struct sockaddr_ipx *sipx = (struct sockaddr_ipx *)msg->msg_name;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct ipxhdr *ipx = NULL;
	struct sk_buff *skb;
	int copied, rc;

	lock_sock(sk);
	/* put the autobinding in */
	if (!ipxs->port) {
		struct sockaddr_ipx uaddr;

		uaddr.sipx_port		= 0;
		uaddr.sipx_network 	= 0;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
#ifdef CONFIG_IPX_INTERN
		rc = -ENETDOWN;
		if (!ipxs->intrfc)
			goto out; /* Someone zonked the iface */
		memcpy(uaddr.sipx_node, ipxs->intrfc->if_node, IPX_NODE_LEN);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
#endif	/* CONFIG_IPX_INTERN */

		rc = __ipx_bind(sock, (struct sockaddr *)&uaddr,
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			      sizeof(struct sockaddr_ipx));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (rc)
			goto out;
	}

	rc = -ENOTCONN;
	if (sock_flag(sk, SOCK_ZAPPED))
		goto out;

	skb = skb_recv_datagram(sk, flags & ~MSG_DONTWAIT,
				flags & MSG_DONTWAIT, &rc);
	if (!skb)
		goto out;

	ipx 	= ipx_hdr(skb);
	copied 	= ntohs(ipx->ipx_pktsize) - sizeof(struct ipxhdr);
	if (copied > size) {
		copied = size;
		msg->msg_flags |= MSG_TRUNC;
	}

	rc = skb_copy_datagram_iovec(skb, sizeof(struct ipxhdr), msg->msg_iov,
				     copied);
	if (rc)
		goto out_free;
	if (skb->tstamp.tv64)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		sk->sk_stamp = skb->tstamp;

	if (sipx) {
		sipx->sipx_family	= AF_IPX;
		sipx->sipx_port		= ipx->ipx_source.sock;
		memcpy(sipx->sipx_node, ipx->ipx_source.node, IPX_NODE_LEN);
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		sipx->sipx_network	= IPX_SKB_CB(skb)->ipx_source_net;
		sipx->sipx_type 	= ipx->ipx_type;
		sipx->sipx_zero		= 0;
		msg->msg_namelen	= sizeof(*sipx);
	}
	rc = copied;

out_free:
	skb_free_datagram(sk, skb);
out:
	release_sock(sk);
	return rc;
}
