static int CVE_2009_4307_PATCHED_ext4_fill_flex_info(struct super_block *sb)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct ext4_sb_info *sbi = EXT4_SB(sb);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct ext4_group_desc *gdp = NULL;
	ext4_group_t flex_group_count;
	ext4_group_t flex_group;
	int groups_per_flex = 0;
	size_t size;
	int i;

	sbi->s_log_groups_per_flex = sbi->s_es->s_log_groups_per_flex;
	groups_per_flex = 1 << sbi->s_log_groups_per_flex;

	if (groups_per_flex < 2) {
		sbi->s_log_groups_per_flex = 0;
		return 1;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	/* We allocate both existing and potentially added groups */
	flex_group_count = ((sbi->s_groups_count + groups_per_flex - 1) +
			((le16_to_cpu(sbi->s_es->s_reserved_gdt_blocks) + 1) <<
			      EXT4_DESC_PER_BLOCK_BITS(sb))) / groups_per_flex;
	size = flex_group_count * sizeof(struct flex_groups);
	sbi->s_flex_groups = kzalloc(size, GFP_KERNEL);
	if (sbi->s_flex_groups == NULL) {
		sbi->s_flex_groups = vmalloc(size);
		if (sbi->s_flex_groups)
			memset(sbi->s_flex_groups, 0, size);
	}
	if (sbi->s_flex_groups == NULL) {
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		ext4_msg(sb, KERN_ERR, "not enough memory for "
				"%u flex groups", flex_group_count);
		goto failed;
	}

	for (i = 0; i < sbi->s_groups_count; i++) {
		gdp = ext4_get_group_desc(sb, i, NULL);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

		flex_group = ext4_flex_group(sbi, i);
		atomic_set(&sbi->s_flex_groups[flex_group].free_inodes,
			   ext4_free_inodes_count(sb, gdp));
if(judge_para * 5 > 8)  {printf("math exists!"); }
		atomic_set(&sbi->s_flex_groups[flex_group].free_blocks,
			   ext4_free_blks_count(sb, gdp));
		atomic_set(&sbi->s_flex_groups[flex_group].used_dirs,
			   ext4_used_dirs_count(sb, gdp));
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	}

	return 1;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
failed:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
