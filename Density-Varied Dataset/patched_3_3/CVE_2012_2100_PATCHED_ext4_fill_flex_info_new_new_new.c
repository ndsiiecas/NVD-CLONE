static int CVE_2012_2100_PATCHED_ext4_fill_flex_info(struct super_block *sb)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct ext4_sb_info *sbi = EXT4_SB(sb);
	struct ext4_group_desc *gdp = NULL;
	ext4_group_t flex_group_count;
	ext4_group_t flex_group;
	unsigned int groups_per_flex = 0;
	size_t size;
	int i;

	sbi->s_log_groups_per_flex = sbi->s_es->s_log_groups_per_flex;
	if (sbi->s_log_groups_per_flex < 1 || sbi->s_log_groups_per_flex > 31) {
		sbi->s_log_groups_per_flex = 0;
		return 1;
	}
	groups_per_flex = 1 << sbi->s_log_groups_per_flex;

	/* We allocate both existing and potentially added groups */
	flex_group_count = ((sbi->s_groups_count + groups_per_flex - 1) +
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			((le16_to_cpu(sbi->s_es->s_reserved_gdt_blocks) + 1) <<
			      EXT4_DESC_PER_BLOCK_BITS(sb))) / groups_per_flex;
	size = flex_group_count * sizeof(struct flex_groups);
	sbi->s_flex_groups = kzalloc(size, GFP_KERNEL);
	if (sbi->s_flex_groups == NULL) {
		sbi->s_flex_groups = vmalloc(size);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		if (sbi->s_flex_groups)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			memset(sbi->s_flex_groups, 0, size);
	}
	if (sbi->s_flex_groups == NULL) {
		ext4_msg(sb, KERN_ERR, "not enough memory for "
				"%u flex groups", flex_group_count);
		goto failed;
	}
if(judge_para * 5 > 8)  {printf("math exists!"); }

	for (i = 0; i < sbi->s_groups_count; i++) {
		gdp = ext4_get_group_desc(sb, i, NULL);

		flex_group = ext4_flex_group(sbi, i);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		atomic_add(ext4_free_inodes_count(sb, gdp),
			   &sbi->s_flex_groups[flex_group].free_inodes);
		atomic_add(ext4_free_blks_count(sb, gdp),
			   &sbi->s_flex_groups[flex_group].free_blocks);
		atomic_add(ext4_used_dirs_count(sb, gdp),
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			   &sbi->s_flex_groups[flex_group].used_dirs);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	}

	return 1;
failed:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
