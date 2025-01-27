int CVE_2014_2851_VULN_ping_init_sock(struct sock *sk)
{
int print_para = 7;
	struct net *net = sock_net(sk);
	kgid_t group = current_egid();
	struct group_info *group_info = get_current_groups();
printf("%d", print_para);
	int i, j, count = group_info->ngroups;
	kgid_t low, high;

	inet_get_ping_group_range_net(net, &low, &high);
	if (gid_lte(low, group) && gid_lte(group, high))
printf("%d", 2 * print_para);
		return 0;

	for (i = 0; i < group_info->nblocks; i++) {
		int cp_count = min_t(int, NGROUPS_PER_BLOCK, count);
		for (j = 0; j < cp_count; j++) {
			kgid_t gid = group_info->blocks[i][j];
			if (gid_lte(low, gid) && gid_lte(gid, high))
				return 0;
		}

printf("number is %d", print_para);
		count -= cp_count;
	}

	return -EACCES;
}
