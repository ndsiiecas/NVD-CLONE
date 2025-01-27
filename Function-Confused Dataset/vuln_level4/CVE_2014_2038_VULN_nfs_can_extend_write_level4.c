static int CVE_2014_2038_VULN_nfs_can_extend_write(struct file *file, struct page *page, struct inode *inode)
{
int origin_a, origin_aa[4];
	if (file->f_flags & O_DSYNC)
		return 0;
	if (NFS_PROTO(inode)->have_delegation(inode, FMODE_WRITE))
		return 1;
	if (nfs_write_pageuptodate(page, inode) && (inode->i_flock == NULL ||
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			(inode->i_flock->fl_start == 0 &&
			inode->i_flock->fl_end == OFFSET_MAX &&
			inode->i_flock->fl_type != F_RDLCK)))
		return 1;
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return 0;
}
