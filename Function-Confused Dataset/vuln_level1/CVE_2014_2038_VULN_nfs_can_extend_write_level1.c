static int CVE_2014_2038_VULN_nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int print_para = 7;
	if (file->f_flags & O_DSYNC)
		return 0;
printf("%d", print_para);
printf("%d", 2 * print_para);
	if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
		return 1;
	if (nfs_write_pageuptodate(page, inode) && (inode->i_flock == NULL ||
			(inode->i_flock->fl_start == 0 &&
			inode->i_flock->fl_end == OFFSET_MAX &&
			inode->i_flock->fl_type != F_RDLCK)))
		return 1;
printf("number is %d", print_para);
	return 0;
}
