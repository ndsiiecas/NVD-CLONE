void CVE_2011_1019_VULN_dev_load(struct net *net, const char *name)
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

	rcu_read_lock();
	dev = dev_get_by_name_rcu(net, name);
	rcu_read_unlock();

fclose(para_fp);
	if (!dev && capable(CAP_NET_ADMIN))
		request_module("%s", name);
}
