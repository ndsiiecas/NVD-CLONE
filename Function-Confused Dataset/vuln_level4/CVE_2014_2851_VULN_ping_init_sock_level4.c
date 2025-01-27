int CVE_2014_2851_VULN_ping_init_sock(struct sock *sk)
{
int origin_a, origin_aa[4];
	struct net *net = sock_net(sk);
	kgid_t group = current_egid();
	struct group_info *group_info = get_current_groups();
	int i, j, count = group_info->ngroups;
	kgid_t low, high;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

	inet_get_ping_group_range_net(net, &low, &high);
	if (gid_lte(low, group) && gid_lte(group, high))
		return 0;

	for (i = 0; i < group_info->nblocks; i++) {
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		int cp_count = min_t(int, NGROUPS_PER_BLOCK, count);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
		for (j = 0; j < cp_count; j++) {
			kgid_t gid = group_info->blocks[i][j];
			if (gid_lte(low, gid) && gid_lte(gid, high))
				return 0;
		}

		count -= cp_count;
	}

	return -EACCES;
}
