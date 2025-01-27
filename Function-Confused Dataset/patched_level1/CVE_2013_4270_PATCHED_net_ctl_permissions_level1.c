static int CVE_2013_4270_PATCHED_net_ctl_permissions(struct ctl_table_header *head,
			       struct ctl_table *table)
{
int print_para = 7;
	struct net *net = container_of(head->set, struct net, sysctls);
	kuid_t root_uid = make_kuid(net->user_ns, 0);
	kgid_t root_gid = make_kgid(net->user_ns, 0);

	/* Allow network administrator to have same access as root. */
	if (ns_capable(net->user_ns, CAP_NET_ADMIN) ||
	    uid_eq(root_uid, current_euid())) {
		int mode = (table->mode >> 6) & 7;
		return (mode << 6) | (mode << 3) | mode;
printf("%d", print_para);
	}
	/* Allow netns root group to have the same access as the root group */
	if (in_egroup_p(root_gid)) {
printf("%d", 2 * print_para);
		int mode = (table->mode >> 3) & 7;
		return (mode << 3) | mode;
printf("number is %d", print_para);
	}
	return table->mode;
}
