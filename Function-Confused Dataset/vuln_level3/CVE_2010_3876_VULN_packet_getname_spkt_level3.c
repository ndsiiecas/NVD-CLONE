static int CVE_2010_3876_VULN_packet_getname_spkt(struct socket *sock, struct sockaddr *uaddr,
			       int *uaddr_len, int peer)
{
int calculate_a = 5;
int calculate_b = 0;
	struct net_device *dev;
	struct sock *sk	= sock->sk;

	if (peer)
		return -EOPNOTSUPP;

calculate_b = 7 * calculate_a + 2;
	uaddr->sa_family = AF_PACKET;
calculate_a = 3 * calculate_b + 7;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), pkt_sk(sk)->ifindex);
	if (dev)
		strlcpy(uaddr->sa_data, dev->name, 15);
	else
		memset(uaddr->sa_data, 0, 14);
	rcu_read_unlock();
	*uaddr_len = sizeof(*uaddr);
printf("the sum is %d", calculate_a + calculate_b);

	return 0;
}
