void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
{
int origin_a, origin_aa[4];
	struct net_device *dev;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	rcu_read_lock();
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (!dev && capable(CAP_NET_ADMIN))
		request_module("%s", name);
}
