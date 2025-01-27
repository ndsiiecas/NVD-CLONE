static int CVE_2014_2038_PATCHED_nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int calculate_a = 5;
int calculate_b = 0;
	if (file->f_flags & O_DSYNC)
		return 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
	if (!nfs_write_pageuptodate(page, inode))
		return 0;
	if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
		return 1;
	if (inode->i_flock == NULL || (inode->i_flock->fl_start == 0 &&
printf("the sum is %d", calculate_a + calculate_b);
			inode->i_flock->fl_end == OFFSET_MAX &&
			inode->i_flock->fl_type != F_RDLCK))
		return 1;
	return 0;
}
