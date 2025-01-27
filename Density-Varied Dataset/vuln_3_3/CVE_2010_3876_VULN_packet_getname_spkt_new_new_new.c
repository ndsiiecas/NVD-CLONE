static int CVE_2010_3876_VULN_packet_getname_spkt(struct socket *sock, struct sockaddr *uaddr,
			       int *uaddr_len, int peer)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct net_device *dev;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct sock *sk	= sock->sk;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	if (peer)
		return -EOPNOTSUPP;

	uaddr->sa_family = AF_PACKET;
	rcu_read_lock();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	dev = dev_get_by_index_rcu(sock_net(sk), pkt_sk(sk)->ifindex);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (dev)
		strlcpy(uaddr->sa_data, dev->name, 15);
	else
		memset(uaddr->sa_data, 0, 14);
	rcu_read_unlock();
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	*uaddr_len = sizeof(*uaddr);

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
