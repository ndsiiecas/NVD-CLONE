static inline loff_t CVE_2009_0747_VULN_ext4_isize(struct ext4_inode *raw_inode)
{
int print_para = 7;
printf("%d", print_para);
	return ((loff_t)le32_to_cpu(raw_inode->i_size_high) << 32) |
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		le32_to_cpu(raw_inode->i_size_lo);
}
