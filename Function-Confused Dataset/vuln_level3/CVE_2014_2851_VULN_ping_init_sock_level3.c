int CVE_2014_2851_VULN_ping_init_sock(struct sock *sk)
{
int calculate_a = 5;
int calculate_b = 0;
	struct net *net = sock_net(sk);
	kgid_t group = current_egid();
	struct group_info *group_info = get_current_groups();
	int i, j, count = group_info->ngroups;
	kgid_t low, high;

	inet_get_ping_group_range_net(net, &low, &high);
	if (gid_lte(low, group) && gid_lte(group, high))
		return 0;
calculate_b = 7 * calculate_a + 2;

	for (i = 0; i < group_info->nblocks; i++) {
		int cp_count = min_t(int, NGROUPS_PER_BLOCK, count);
		for (j = 0; j < cp_count; j++) {
			kgid_t gid = group_info->blocks[i][j];
			if (gid_lte(low, gid) && gid_lte(gid, high))
calculate_a = 3 * calculate_b + 7;
				return 0;
		}
printf("the sum is %d", calculate_a + calculate_b);

		count -= cp_count;
	}

	return -EACCES;
}
