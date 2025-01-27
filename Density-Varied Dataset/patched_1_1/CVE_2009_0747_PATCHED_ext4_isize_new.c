static inline loff_t CVE_2009_0747_PATCHED_ext4_isize(struct ext4_inode *raw_inode)
{
int judge_para = 3;
	if (S_ISREG(le16_to_cpu(raw_inode->i_mode)))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
		return ((loff_t)le32_to_cpu(raw_inode->i_size_high) << 32) |
			le32_to_cpu(raw_inode->i_size_lo);
	else
		return (loff_t) le32_to_cpu(raw_inode->i_size_lo);
}
