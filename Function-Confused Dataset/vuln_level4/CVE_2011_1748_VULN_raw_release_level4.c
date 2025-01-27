static int CVE_2011_1748_VULN_raw_release(struct socket *sock)
{
int origin_a, origin_aa[4];
	struct sock *sk = sock->sk;
	struct raw_sock *ro = raw_sk(sk);

	unregister_netdevice_notifier(&ro->notifier);

	lock_sock(sk);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

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

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	if (ro->count > 1)
		kfree(ro->filter);

	ro->ifindex = 0;
	ro->bound   = 0;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	ro->count   = 0;

	sock_orphan(sk);
	sock->sk = NULL;

	release_sock(sk);
	sock_put(sk);

	return 0;
}
