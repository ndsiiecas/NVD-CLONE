static int CVE_2010_3876_VULN_packet_getname_spkt(struct socket *sock, struct sockaddr *uaddr,
			       int *uaddr_len, int peer)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct net_device *dev;
	struct sock *sk	= sock->sk;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	if (peer)
		return -EOPNOTSUPP;

	uaddr->sa_family = AF_PACKET;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), pkt_sk(sk)->ifindex);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (dev)
		strlcpy(uaddr->sa_data, dev->name, 15);
	else
		memset(uaddr->sa_data, 0, 14);
	rcu_read_unlock();
	*uaddr_len = sizeof(*uaddr);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
