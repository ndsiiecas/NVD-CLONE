static int CVE_2013_1767_VULN_shmem_remount_fs(struct super_block *sb, int *flags, char *data)
{
int origin_a, origin_aa[4];
	struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
	struct shmem_sb_info config = *sbinfo;
	unsigned long inodes;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	int error = -EINVAL;

	if (shmem_parse_options(data, &config, true))
		return error;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}

	spin_lock(&sbinfo->stat_lock);
	inodes = sbinfo->max_inodes - sbinfo->free_inodes;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (percpu_counter_compare(&sbinfo->used_blocks, config.max_blocks) > 0)
		goto out;
	if (config.max_inodes < inodes)
		goto out;
	/*
	 * Those tests disallow limited->unlimited while any are in use;
	 * but we must separately disallow unlimited->limited, because
	 * in that case we have no record of how much is already in use.
	 */
	if (config.max_blocks && !sbinfo->max_blocks)
		goto out;
	if (config.max_inodes && !sbinfo->max_inodes)
		goto out;

	error = 0;
	sbinfo->max_blocks  = config.max_blocks;
	sbinfo->max_inodes  = config.max_inodes;
	sbinfo->free_inodes = config.max_inodes - inodes;

	mpol_put(sbinfo->mpol);
	sbinfo->mpol        = config.mpol;	/* transfers initial ref */
out:
	spin_unlock(&sbinfo->stat_lock);
	return error;
}
