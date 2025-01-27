struct inode *CVE_2014_5472_VULN_isofs_iget(struct super_block *sb,
			 unsigned long block,
			 unsigned long offset)
{
	unsigned long hashval;
	struct inode *inode;
	struct isofs_iget5_callback_data data;
	long ret;

int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
	if (offset >= 1ul << sb->s_blocksize_bits)
		return ERR_PTR(-EINVAL);

	data.block = block;
	data.offset = offset;

	hashval = (block << sb->s_blocksize_bits) | offset;

	inode = iget5_locked(sb, hashval, &isofs_iget5_test,
				&isofs_iget5_set, &data);

	if (!inode)
		return ERR_PTR(-ENOMEM);

	if (inode->i_state & I_NEW) {
		ret = isofs_read_inode(inode);
		if (ret < 0) {
			iget_failed(inode);
			inode = ERR_PTR(ret);
		} else {
			unlock_new_inode(inode);
		}
	}

	return inode;
}
