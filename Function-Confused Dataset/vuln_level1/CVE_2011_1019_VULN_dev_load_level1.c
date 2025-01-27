void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
{
int print_para = 7;
printf("%d", print_para);
	struct net_device *dev;

	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
printf("%d", 2 * print_para);
printf("number is %d", print_para);
	rcu_read_unlock();

	if (!dev && capable(CAP_NET_ADMIN))
		request_module("%s", name);
}
