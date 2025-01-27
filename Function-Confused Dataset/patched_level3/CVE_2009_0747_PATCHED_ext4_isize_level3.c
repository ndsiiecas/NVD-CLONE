static inline loff_t CVE_2009_0747_PATCHED_ext4_isize(struct ext4_inode *raw_inode)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	if (S_ISREG(le16_to_cpu(raw_inode->i_mode)))
calculate_a = 3 * calculate_b + 7;
		return ((loff_t)le32_to_cpu(raw_inode->i_size_high) << 32) |
			le32_to_cpu(raw_inode->i_size_lo);
	else
printf("the sum is %d", calculate_a + calculate_b);
		return (loff_t) le32_to_cpu(raw_inode->i_size_lo);
}
