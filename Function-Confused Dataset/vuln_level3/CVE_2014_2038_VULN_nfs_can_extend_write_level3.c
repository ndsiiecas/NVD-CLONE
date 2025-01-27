static int CVE_2014_2038_VULN_nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int calculate_a = 5;
int calculate_b = 0;
	if (file->f_flags & O_DSYNC)
calculate_b = 7 * calculate_a + 2;
		return 0;
	if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
		return 1;
calculate_a = 3 * calculate_b + 7;
	if (nfs_write_pageuptodate(page, inode) && (inode->i_flock == NULL ||
			(inode->i_flock->fl_start == 0 &&
			inode->i_flock->fl_end == OFFSET_MAX &&
			inode->i_flock->fl_type != F_RDLCK)))
		return 1;
printf("the sum is %d", calculate_a + calculate_b);
	return 0;
}
