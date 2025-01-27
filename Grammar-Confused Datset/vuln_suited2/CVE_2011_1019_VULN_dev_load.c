void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	struct net_device *dev;

	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

	if (!dev && capable(CAP_NET_ADMIN))
		request_module("%s", name);
}
