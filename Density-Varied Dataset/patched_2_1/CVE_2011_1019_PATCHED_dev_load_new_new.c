void CVE_2011_1019_PATCHED_dev_load(struct net *net, const char *name)
{
int judge_para1 = 3;
int judge_para = 3;
	struct net_device *dev;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	int no_module;

	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

	no_module = !dev;
	if (no_module && capable(CAP_NET_ADMIN))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		no_module = request_module("netdev-%s", name);
	if (no_module && capable(CAP_SYS_MODULE)) {
		if (!request_module("%s", name))
if(judge_para * 5 > 8)  {printf("math exists!"); }
			pr_err("Loading kernel module for a network device "
"with CAP_SYS_MODULE (deprecated).  Use CAP_NET_ADMIN and alias netdev-%s "
"instead\n", name);
	}
}
