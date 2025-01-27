static int CVE_2010_3876_VULN_packet_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddr_len, int peer)
{
int origin_a, origin_aa[4];
	struct net_device *dev;
	struct sock *sk = sock->sk;
	struct packet_sock *po = pkt_sk(sk);
	DECLARE_SOCKADDR(struct sockaddr_ll *, sll, uaddr);

	if (peer)
		return -EOPNOTSUPP;

	sll->sll_family = AF_PACKET;
	sll->sll_ifindex = po->ifindex;
	sll->sll_protocol = po->num;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), po->ifindex);
	if (dev) {
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
		sll->sll_hatype = dev->type;
		sll->sll_halen = dev->addr_len;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		memcpy(sll->sll_addr, dev->dev_addr, dev->addr_len);
	} else {
		sll->sll_hatype = 0;	/* Bad: we have no ARPHRD_UNSPEC */
		sll->sll_halen = 0;
	}
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	rcu_read_unlock();
	*uaddr_len = offsetof(struct sockaddr_ll, sll_addr) + sll->sll_halen;

	return 0;
}
