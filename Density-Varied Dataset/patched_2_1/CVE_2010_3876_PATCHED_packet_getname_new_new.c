static int CVE_2010_3876_PATCHED_packet_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddr_len, int peer)
{
int judge_para1 = 3;
int judge_para = 3;
	struct net_device *dev;
	struct sock *sk = sock->sk;
	struct packet_sock *po = pkt_sk(sk);
	DECLARE_SOCKADDR(struct sockaddr_ll *, sll, uaddr);

	if (peer)
		return -EOPNOTSUPP;

	sll->sll_family = AF_PACKET;
	sll->sll_ifindex = po->ifindex;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	sll->sll_protocol = po->num;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	sll->sll_pkttype = 0;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), po->ifindex);
	if (dev) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		sll->sll_hatype = dev->type;
		sll->sll_halen = dev->addr_len;
		memcpy(sll->sll_addr, dev->dev_addr, dev->addr_len);
	} else {
		sll->sll_hatype = 0;	/* Bad: we have no ARPHRD_UNSPEC */
		sll->sll_halen = 0;
	}
	rcu_read_unlock();
	*uaddr_len = offsetof(struct sockaddr_ll, sll_addr) + sll->sll_halen;

	return 0;
}
