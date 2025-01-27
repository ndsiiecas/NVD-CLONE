void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
{
	struct net_device *dev;

int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

	if (!dev && capable(CAP_NET_ADMIN))
		request_module("%s", name);
}
