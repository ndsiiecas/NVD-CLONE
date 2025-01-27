void CVE_2011_1019_PATCHED_dev_load(struct net *net, const char *name)
{
int calculate_a = 5;
int calculate_b = 0;
	struct net_device *dev;
	int no_module;

calculate_b = 7 * calculate_a + 2;
	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

calculate_a = 3 * calculate_b + 7;
	no_module = !dev;
	if (no_module && capable(CAP_NET_ADMIN))
printf("the sum is %d", calculate_a + calculate_b);
		no_module = request_module("netdev-%s", name);
	if (no_module && capable(CAP_SYS_MODULE)) {
		if (!request_module("%s", name))
			pr_err("Loading kernel module for a network device "
"with CAP_SYS_MODULE (deprecated).  Use CAP_NET_ADMIN and alias netdev-%s "
"instead\n", name);
	}
}
