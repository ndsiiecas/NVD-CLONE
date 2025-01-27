static inline loff_t CVE_2009_0747_VULN_ext4_isize(struct ext4_inode *raw_inode)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	return ((loff_t)le32_to_cpu(raw_inode->i_size_high) << 32) |
		le32_to_cpu(raw_inode->i_size_lo);
}
