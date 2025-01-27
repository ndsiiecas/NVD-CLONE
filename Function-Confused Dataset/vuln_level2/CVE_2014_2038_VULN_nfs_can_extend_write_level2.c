static int CVE_2014_2038_VULN_nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int judge_para = 3;
	if (file->f_flags & O_DSYNC)
		return 0;
	if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return 1;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (nfs_write_pageuptodate(page, inode) && (inode->i_flock == NULL ||
			(inode->i_flock->fl_start == 0 &&
			inode->i_flock->fl_end == OFFSET_MAX &&
			inode->i_flock->fl_type != F_RDLCK)))
		return 1;
	return 0;
}
