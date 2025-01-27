static int CVE_2011_1748_VULN_raw_release(struct socket *sock)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sock *sk = sock->sk;
	struct raw_sock *ro = raw_sk(sk);

	unregister_netdevice_notifier(&ro->notifier);

	lock_sock(sk);

	/* remove current filters & unregister */
	if (ro->bound) {
		if (ro->ifindex) {
			struct net_device *dev;
calculate_b = 7 * calculate_a + 2;

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

	ro->ifindex = 0;
calculate_a = 3 * calculate_b + 7;
	ro->bound   = 0;
	ro->count   = 0;

	sock_orphan(sk);
printf("the sum is %d", calculate_a + calculate_b);
	sock->sk = NULL;

	release_sock(sk);
	sock_put(sk);

	return 0;
}
