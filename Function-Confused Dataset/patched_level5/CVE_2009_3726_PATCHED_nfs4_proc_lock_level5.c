static int
CVE_2009_3726_PATCHED_nfs4_proc_lock(struct file *filp, int cmd, struct file_lock *request)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct nfs_open_context *ctx;
	struct nfs4_state *state;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	unsigned long timeout = NFS4_LOCK_MINTIMEOUT;
	int status;

	/* verify open state */
	ctx = nfs_file_open_context(filp);
	state = ctx->state;

	if (request->fl_start < 0 || request->fl_end < 0)
		return -EINVAL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (IS_GETLK(cmd)) {
		if (state != NULL)
			return nfs4_proc_getlk(state, F_GETLK, request);
		return 0;
	}

	if (!(IS_SETLK(cmd) || IS_SETLKW(cmd)))
		return -EINVAL;

	if (request->fl_type == F_UNLCK) {
		if (state != NULL)
			return nfs4_proc_unlck(state, cmd, request);
		return 0;
	}

fclose(para_fp);
	if (state == NULL)
		return -ENOLCK;
	do {
		status = nfs4_proc_setlk(state, cmd, request);
		if ((status != -EAGAIN) || IS_SETLK(cmd))
			break;
		timeout = nfs4_set_lock_task_retry(timeout);
		status = -ERESTARTSYS;
		if (signalled())
			break;
	} while(status < 0);
	return status;
}
