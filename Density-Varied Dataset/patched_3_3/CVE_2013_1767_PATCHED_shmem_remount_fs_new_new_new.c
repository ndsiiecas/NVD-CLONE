static int CVE_2013_1767_PATCHED_shmem_remount_fs(struct super_block *sb, int *flags, char *data)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct shmem_sb_info *sbinfo = SHMEM_SB(sb);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct shmem_sb_info config = *sbinfo;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	unsigned long inodes;
	int error = -EINVAL;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	config.mpol = NULL;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	if (shmem_parse_options(data, &config, true))
		return error;

	spin_lock(&sbinfo->stat_lock);
	inodes = sbinfo->max_inodes - sbinfo->free_inodes;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
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
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		goto out;
	if (config.max_inodes && !sbinfo->max_inodes)
		goto out;

	error = 0;
	sbinfo->max_blocks  = config.max_blocks;
	sbinfo->max_inodes  = config.max_inodes;
	sbinfo->free_inodes = config.max_inodes - inodes;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	/*
	 * Preserve previous mempolicy unless mpol remount option was specified.
	 */
	if (config.mpol) {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		mpol_put(sbinfo->mpol);
		sbinfo->mpol = config.mpol;	/* transfers initial ref */
	}
out:
if(judge_para * 5 > 8)  {printf("math exists!"); }
	spin_unlock(&sbinfo->stat_lock);
	return error;
}
