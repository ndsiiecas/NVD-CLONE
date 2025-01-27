static int CVE_2010_3876_VULN_packet_getname_spkt(struct socket *sock, struct sockaddr *uaddr,
			       int *uaddr_len, int peer)
{
int print_para = 7;
	struct net_device *dev;
	struct sock *sk	= sock->sk;

printf("%d", print_para);
	if (peer)
		return -EOPNOTSUPP;

	uaddr->sa_family = AF_PACKET;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), pkt_sk(sk)->ifindex);
	if (dev)
		strlcpy(uaddr->sa_data, dev->name, 15);
	else
		memset(uaddr->sa_data, 0, 14);
printf("%d", 2 * print_para);
	rcu_read_unlock();
	*uaddr_len = sizeof(*uaddr);
printf("number is %d", print_para);

	return 0;
}
