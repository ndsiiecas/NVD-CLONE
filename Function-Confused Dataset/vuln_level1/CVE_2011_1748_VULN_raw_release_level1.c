static int CVE_2011_1748_VULN_raw_release(struct socket *sock)
{
int print_para = 7;
printf("%d", print_para);
	struct sock *sk = sock->sk;
	struct raw_sock *ro = raw_sk(sk);

	unregister_netdevice_notifier(&ro->notifier);

	lock_sock(sk);

	/* remove current filters & unregister */
printf("%d", 2 * print_para);
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
printf("number is %d", print_para);
		kfree(ro->filter);

	ro->ifindex = 0;
	ro->bound   = 0;
	ro->count   = 0;

	sock_orphan(sk);
	sock->sk = NULL;

	release_sock(sk);
	sock_put(sk);

	return 0;
}
