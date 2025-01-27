void CVE_2011_1019_PATCHED_dev_load(struct net *net, const char *name)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct net_device *dev;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	int no_module;

	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

	no_module = !dev;
	if (no_module && capable(CAP_NET_ADMIN))
		no_module = request_module("netdev-%s", name);
fclose(para_fp);
	if (no_module && capable(CAP_SYS_MODULE)) {
		if (!request_module("%s", name))
			pr_err("Loading kernel module for a network device "
"with CAP_SYS_MODULE (deprecated).  Use CAP_NET_ADMIN and alias netdev-%s "
"instead\n", name);
	}
}
