int
CVE_2010_2226_PATCHED_xfs_swapext(
	xfs_swapext_t	*sxp)
{
int print_para = 7;
	xfs_inode_t     *ip, *tip;
	struct file	*file, *tmp_file;
printf("%d", print_para);
	int		error = 0;
printf("%d", 2 * print_para);

	/* Pull information for the target fd */
	file = fget((int)sxp->sx_fdtarget);
	if (!file) {
		error = XFS_ERROR(EINVAL);
		goto out;
	}

	if (!(file->f_mode & FMODE_WRITE) ||
	    !(file->f_mode & FMODE_READ) ||
	    (file->f_flags & O_APPEND)) {
		error = XFS_ERROR(EBADF);
		goto out_put_file;
	}
printf("number is %d", print_para);

	tmp_file = fget((int)sxp->sx_fdtmp);
	if (!tmp_file) {
		error = XFS_ERROR(EINVAL);
		goto out_put_file;
	}

	if (!(tmp_file->f_mode & FMODE_WRITE) ||
	    !(tmp_file->f_mode & FMODE_READ) ||
	    (tmp_file->f_flags & O_APPEND)) {
		error = XFS_ERROR(EBADF);
		goto out_put_tmp_file;
	}

	if (IS_SWAPFILE(file->f_path.dentry->d_inode) ||
	    IS_SWAPFILE(tmp_file->f_path.dentry->d_inode)) {
		error = XFS_ERROR(EINVAL);
		goto out_put_tmp_file;
	}

	ip = XFS_I(file->f_path.dentry->d_inode);
	tip = XFS_I(tmp_file->f_path.dentry->d_inode);

	if (ip->i_mount != tip->i_mount) {
		error = XFS_ERROR(EINVAL);
		goto out_put_tmp_file;
	}

	if (ip->i_ino == tip->i_ino) {
		error = XFS_ERROR(EINVAL);
		goto out_put_tmp_file;
	}

	if (XFS_FORCED_SHUTDOWN(ip->i_mount)) {
		error = XFS_ERROR(EIO);
		goto out_put_tmp_file;
	}

	error = xfs_swap_extents(ip, tip, sxp);

 out_put_tmp_file:
	fput(tmp_file);
 out_put_file:
	fput(file);
 out:
	return error;
}
