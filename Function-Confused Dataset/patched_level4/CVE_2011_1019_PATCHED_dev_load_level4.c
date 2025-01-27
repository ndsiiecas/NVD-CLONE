void CVE_2011_1019_PATCHED_dev_load(struct net *net, const char *name)
{
int origin_a, origin_aa[4];
	struct net_device *dev;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int no_module;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

	no_module = !dev;
	if (no_module && capable(CAP_NET_ADMIN))
		no_module = request_module("netdev-%s", name);
	if (no_module && capable(CAP_SYS_MODULE)) {
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		if (!request_module("%s", name))
			pr_err("Loading kernel module for a network device "
"with CAP_SYS_MODULE (deprecated).  Use CAP_NET_ADMIN and alias netdev-%s "
"instead\n", name);
	}
}
