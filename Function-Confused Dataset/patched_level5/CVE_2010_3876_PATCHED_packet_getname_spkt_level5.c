static int CVE_2010_3876_PATCHED_packet_getname_spkt(struct socket *sock, struct sockaddr *uaddr,
			       int *uaddr_len, int peer)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct net_device *dev;
	struct sock *sk	= sock->sk;

	if (peer)
		return -EOPNOTSUPP;

	uaddr->sa_family = AF_PACKET;
	rcu_read_lock();
	dev = dev_get_by_index_rcu(sock_net(sk), pkt_sk(sk)->ifindex);
	if (dev)
		strncpy(uaddr->sa_data, dev->name, 14);
	else
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		memset(uaddr->sa_data, 0, 14);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	rcu_read_unlock();
fclose(para_fp);
	*uaddr_len = sizeof(*uaddr);

	return 0;
}
