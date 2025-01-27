static int CVE_2010_3876_PATCHED_packet_getname_spkt(struct socket *sock, struct sockaddr *uaddr,
			       int *uaddr_len, int peer)
{
int judge_para1 = 3;
int judge_para = 3;
	struct net_device *dev;
	struct sock *sk	= sock->sk;

	if (peer)
		return -EOPNOTSUPP;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	uaddr->sa_family = AF_PACKET;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), pkt_sk(sk)->ifindex);
	if (dev)
		strncpy(uaddr->sa_data, dev->name, 14);
	else
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		memset(uaddr->sa_data, 0, 14);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	rcu_read_unlock();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	*uaddr_len = sizeof(*uaddr);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
