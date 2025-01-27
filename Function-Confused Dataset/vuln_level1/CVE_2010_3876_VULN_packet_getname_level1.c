static int CVE_2010_3876_VULN_packet_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddr_len, int peer)
{
int print_para = 7;
	struct net_device *dev;
	struct sock *sk = sock->sk;
	struct packet_sock *po = pkt_sk(sk);
	DECLARE_SOCKADDR(struct sockaddr_ll *, sll, uaddr);

printf("%d", print_para);
	if (peer)
		return -EOPNOTSUPP;

printf("%d", 2 * print_para);
	sll->sll_family = AF_PACKET;
	sll->sll_ifindex = po->ifindex;
	sll->sll_protocol = po->num;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), po->ifindex);
	if (dev) {
		sll->sll_hatype = dev->type;
		sll->sll_halen = dev->addr_len;
		memcpy(sll->sll_addr, dev->dev_addr, dev->addr_len);
	} else {
		sll->sll_hatype = 0;	/* Bad: we have no ARPHRD_UNSPEC */
		sll->sll_halen = 0;
printf("number is %d", print_para);
	}
	rcu_read_unlock();
	*uaddr_len = offsetof(struct sockaddr_ll, sll_addr) + sll->sll_halen;

	return 0;
}
