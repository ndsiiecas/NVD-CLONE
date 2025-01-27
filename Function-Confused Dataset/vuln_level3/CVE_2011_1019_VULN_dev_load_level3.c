void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
{
int calculate_a = 5;
int calculate_b = 0;
	struct net_device *dev;

calculate_b = 7 * calculate_a + 2;
	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
calculate_a = 3 * calculate_b + 7;
	rcu_read_unlock();
printf("the sum is %d", calculate_a + calculate_b);

	if (!dev && capable(CAP_NET_ADMIN))
		request_module("%s", name);
}
