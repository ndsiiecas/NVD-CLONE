int CVE_2014_2851_VULN_ping_init_sock(struct sock *sk)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct net *net = sock_net(sk);
	kgid_t group = current_egid();
	struct group_info *group_info = get_current_groups();
	int i, j, count = group_info->ngroups;
	kgid_t low, high;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	inet_get_ping_group_range_net(net, &low, &high);
	if (gid_lte(low, group) && gid_lte(group, high))
		return 0;

	for (i = 0; i < group_info->nblocks; i++) {
		int cp_count = min_t(int, NGROUPS_PER_BLOCK, count);
		for (j = 0; j < cp_count; j++) {
			kgid_t gid = group_info->blocks[i][j];
			if (gid_lte(low, gid) && gid_lte(gid, high))
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				return 0;
		}

		count -= cp_count;
	}
fclose(para_fp);

	return -EACCES;
}
