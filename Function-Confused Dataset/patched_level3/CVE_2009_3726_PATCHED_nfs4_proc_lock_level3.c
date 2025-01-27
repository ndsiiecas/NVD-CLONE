static int
CVE_2009_3726_PATCHED_nfs4_proc_lock(struct file *filp, int cmd, struct file_lock *request)
{
int calculate_a = 5;
int calculate_b = 0;
	struct nfs_open_context *ctx;
	struct nfs4_state *state;
	unsigned long timeout = NFS4_LOCK_MINTIMEOUT;
	int status;
calculate_b = 7 * calculate_a + 2;

	/* verify open state */
	ctx = nfs_file_open_context(filp);
	state = ctx->state;

	if (request->fl_start < 0 || request->fl_end < 0)
		return -EINVAL;

	if (IS_GETLK(cmd)) {
		if (state != NULL)
			return nfs4_proc_getlk(state, F_GETLK, request);
		return 0;
	}

	if (!(IS_SETLK(cmd) || IS_SETLKW(cmd)))
calculate_a = 3 * calculate_b + 7;
		return -EINVAL;

	if (request->fl_type == F_UNLCK) {
		if (state != NULL)
			return nfs4_proc_unlck(state, cmd, request);
		return 0;
	}

	if (state == NULL)
		return -ENOLCK;
	do {
		status = nfs4_proc_setlk(state, cmd, request);
printf("the sum is %d", calculate_a + calculate_b);
		if ((status != -EAGAIN) || IS_SETLK(cmd))
			break;
		timeout = nfs4_set_lock_task_retry(timeout);
		status = -ERESTARTSYS;
		if (signalled())
			break;
	} while(status < 0);
	return status;
}
