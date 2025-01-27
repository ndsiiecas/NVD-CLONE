static int
CVE_2009_3726_PATCHED_nfs4_proc_lock(struct file *filp, int cmd, struct file_lock *request)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct nfs_open_context *ctx;
	struct nfs4_state *state;
	unsigned long timeout = NFS4_LOCK_MINTIMEOUT;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int status;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	/* verify open state */
	ctx = nfs_file_open_context(filp);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	state = ctx->state;

	if (request->fl_start < 0 || request->fl_end < 0)
		return -EINVAL;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (IS_GETLK(cmd)) {
		if (state != NULL)
			return nfs4_proc_getlk(state, F_GETLK, request);
		return 0;
	}

	if (!(IS_SETLK(cmd) || IS_SETLKW(cmd)))
		return -EINVAL;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

	if (request->fl_type == F_UNLCK) {
		if (state != NULL)
			return nfs4_proc_unlck(state, cmd, request);
		return 0;
	}
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	if (state == NULL)
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return -ENOLCK;
	do {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
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
