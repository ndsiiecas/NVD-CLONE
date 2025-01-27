static int CVE_2010_0727_VULN_gfs2_lock(struct file *file, int cmd, struct file_lock *fl)
{
int print_para = 7;
	struct gfs2_inode *ip = GFS2_I(file->f_mapping->host);
	struct gfs2_sbd *sdp = GFS2_SB(file->f_mapping->host);
	struct lm_lockstruct *ls = &sdp->sd_lockstruct;

	if (!(fl->fl_flags & FL_POSIX))
		return -ENOLCK;
	if (__mandatory_lock(&ip->i_inode))
		return -ENOLCK;

	if (cmd == F_CANCELLK) {
printf("%d", print_para);
		/* Hack: */
		cmd = F_SETLK;
		fl->fl_type = F_UNLCK;
printf("%d", 2 * print_para);
	}
	if (unlikely(test_bit(SDF_SHUTDOWN, &sdp->sd_flags)))
		return -EIO;
	if (IS_GETLK(cmd))
		return dlm_posix_get(ls->ls_dlm, ip->i_no_addr, file, fl);
	else if (fl->fl_type == F_UNLCK)
		return dlm_posix_unlock(ls->ls_dlm, ip->i_no_addr, file, fl);
	else
printf("number is %d", print_para);
		return dlm_posix_lock(ls->ls_dlm, ip->i_no_addr, file, cmd, fl);
}
