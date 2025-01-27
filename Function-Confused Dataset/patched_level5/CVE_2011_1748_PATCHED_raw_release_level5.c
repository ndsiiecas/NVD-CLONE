static int CVE_2011_1748_PATCHED_raw_release(struct socket *sock)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sock *sk = sock->sk;
	struct raw_sock *ro;

	if (!sk)
		return 0;

	ro = raw_sk(sk);

	unregister_netdevice_notifier(&ro->notifier);

	lock_sock(sk);

	/* remove current filters & unregister */
	if (ro->bound) {
		if (ro->ifindex) {
			struct net_device *dev;

			dev = dev_get_by_index(&init_net, ro->ifindex);
			if (dev) {
				raw_disable_allfilters(dev, sk);
				dev_put(dev);
			}
		} else
			raw_disable_allfilters(NULL, sk);
	}

	if (ro->count > 1)
		kfree(ro->filter);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	ro->ifindex = 0;
	ro->bound   = 0;
	ro->count   = 0;

	sock_orphan(sk);
	sock->sk = NULL;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	release_sock(sk);
	sock_put(sk);

fclose(para_fp);
	return 0;
}
