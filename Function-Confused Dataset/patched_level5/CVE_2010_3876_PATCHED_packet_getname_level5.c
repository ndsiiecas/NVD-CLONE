static int CVE_2010_3876_PATCHED_packet_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddr_len, int peer)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct net_device *dev;
	struct sock *sk = sock->sk;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct packet_sock *po = pkt_sk(sk);
	DECLARE_SOCKADDR(struct sockaddr_ll *, sll, uaddr);

	if (peer)
		return -EOPNOTSUPP;

	sll->sll_family = AF_PACKET;
	sll->sll_ifindex = po->ifindex;
	sll->sll_protocol = po->num;
	sll->sll_pkttype = 0;
	rcu_read_lock();
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	dev = dev_get_by_index_rcu(sock_net(sk), po->ifindex);
	if (dev) {
		sll->sll_hatype = dev->type;
fclose(para_fp);
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
