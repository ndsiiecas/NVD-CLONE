static int CVE_2013_4270_VULN_net_ctl_permissions(struct ctl_table_header *head,
			       struct ctl_table *table)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct net *net = container_of(head->set, struct net, sysctls);
	kuid_t root_uid = make_kuid(net->user_ns, 0);
	kgid_t root_gid = make_kgid(net->user_ns, 0);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	/* Allow network administrator to have same access as root. */
	if (ns_capable(net->user_ns, CAP_NET_ADMIN) ||
	    uid_eq(root_uid, current_uid())) {
		int mode = (table->mode >> 6) & 7;
		return (mode << 6) | (mode << 3) | mode;
	}
	/* Allow netns root group to have the same access as the root group */
	if (gid_eq(root_gid, current_gid())) {
		int mode = (table->mode >> 3) & 7;
fclose(para_fp);
		return (mode << 3) | mode;
	}
	return table->mode;
}
