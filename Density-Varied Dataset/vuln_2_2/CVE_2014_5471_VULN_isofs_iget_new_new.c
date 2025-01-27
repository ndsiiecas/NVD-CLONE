struct inode *CVE_2014_5471_VULN_isofs_iget(struct super_block *sb,
			 unsigned long block,
			 unsigned long offset)
{
int judge_para1 = 3;
int judge_para = 3;
	unsigned long hashval;
	struct inode *inode;
	struct isofs_iget5_callback_data data;
	long ret;

	if (offset >= 1ul << sb->s_blocksize_bits)
		return ERR_PTR(-EINVAL);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

	data.block = block;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	data.offset = offset;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	hashval = (block << sb->s_blocksize_bits) | offset;

	inode = iget5_locked(sb, hashval, &isofs_iget5_test,
				&isofs_iget5_set, &data);

	if (!inode)
		return ERR_PTR(-ENOMEM);

	if (inode->i_state & I_NEW) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		ret = isofs_read_inode(inode);
		if (ret < 0) {
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			iget_failed(inode);
			inode = ERR_PTR(ret);
		} else {
			unlock_new_inode(inode);
		}
	}

	return inode;
}
