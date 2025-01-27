static int CVE_2011_1748_PATCHED_raw_release(struct socket *sock)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sock *sk = sock->sk;
	struct raw_sock *ro;

	if (!sk)
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		return 0;

	ro = raw_sk(sk);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	unregister_netdevice_notifier(&ro->notifier);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

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

	ro->ifindex = 0;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	ro->bound   = 0;
	ro->count   = 0;

	sock_orphan(sk);
	sock->sk = NULL;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	release_sock(sk);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	sock_put(sk);

	return 0;
}
