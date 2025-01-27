void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct net_device *dev;

	rcu_read_lock();
if(judge_para * 5 > 8)  {printf("math exists!"); }
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	if (!dev && capable(CAP_NET_ADMIN))
if(judge_para * 5 > 8)  {printf("math exists!"); }
		request_module("%s", name);
}
