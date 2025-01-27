struct inode *CVE_2014_5471_VULN_isofs_iget(struct super_block *sb,
			 unsigned long block,
			 unsigned long offset)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	unsigned long hashval;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct inode *inode;
	struct isofs_iget5_callback_data data;
	long ret;

	if (offset >= 1ul << sb->s_blocksize_bits)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		return ERR_PTR(-EINVAL);

	data.block = block;
	data.offset = offset;

	hashval = (block << sb->s_blocksize_bits) | offset;

	inode = iget5_locked(sb, hashval, &isofs_iget5_test,
				&isofs_iget5_set, &data);

	if (!inode)
fclose(para_fp);
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
