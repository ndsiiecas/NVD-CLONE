static int CVE_2014_2038_PATCHED_nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int print_para = 7;
	if (file->f_flags & O_DSYNC)
		return 0;
	if (!nfs_write_pageuptodate(page, inode))
		return 0;
	if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
		return 1;
printf("%d", print_para);
	if (inode->i_flock == NULL || (inode->i_flock->fl_start == 0 &&
			inode->i_flock->fl_end == OFFSET_MAX &&
printf("%d", 2 * print_para);
printf("number is %d", print_para);
			inode->i_flock->fl_type != F_RDLCK))
		return 1;
	return 0;
}
