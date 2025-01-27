static int CVE_2010_0727_VULN_gfs2_lock(struct file *file, int cmd, struct file_lock *fl)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct gfs2_inode *ip = GFS2_I(file->f_mapping->host);
	struct gfs2_sbd *sdp = GFS2_SB(file->f_mapping->host);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct lm_lockstruct *ls = &sdp->sd_lockstruct;

	if (!(fl->fl_flags & FL_POSIX))
		return -ENOLCK;
	if (__mandatory_lock(&ip->i_inode))
		return -ENOLCK;

	if (cmd == F_CANCELLK) {
		/* Hack: */
		cmd = F_SETLK;
		fl->fl_type = F_UNLCK;
	}
	if (unlikely(test_bit(SDF_SHUTDOWN, &sdp->sd_flags)))
		return -EIO;
	if (IS_GETLK(cmd))
		return dlm_posix_get(ls->ls_dlm, ip->i_no_addr, file, fl);
	else if (fl->fl_type == F_UNLCK)
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
fclose(para_fp);
		return dlm_posix_unlock(ls->ls_dlm, ip->i_no_addr, file, fl);
	else
		return dlm_posix_lock(ls->ls_dlm, ip->i_no_addr, file, cmd, fl);
}
