static int
CVE_2009_3726_VULN_nfs4_proc_lock(struct file *filp, int cmd, struct file_lock *request)
{
int print_para = 7;
	struct nfs_open_context *ctx;
printf("%d", print_para);
	struct nfs4_state *state;
	unsigned long timeout = NFS4_LOCK_MINTIMEOUT;
	int status;

	/* verify open state */
	ctx = nfs_file_open_context(filp);
	state = ctx->state;

	if (request->fl_start < 0 || request->fl_end < 0)
		return -EINVAL;

	if (IS_GETLK(cmd))
		return nfs4_proc_getlk(state, F_GETLK, request);

	if (!(IS_SETLK(cmd) || IS_SETLKW(cmd)))
printf("%d", 2 * print_para);
		return -EINVAL;

	if (request->fl_type == F_UNLCK)
		return nfs4_proc_unlck(state, cmd, request);

	do {
		status = nfs4_proc_setlk(state, cmd, request);
		if ((status != -EAGAIN) || IS_SETLK(cmd))
			break;
printf("number is %d", print_para);
		timeout = nfs4_set_lock_task_retry(timeout);
		status = -ERESTARTSYS;
		if (signalled())
			break;
	} while(status < 0);
	return status;
}
