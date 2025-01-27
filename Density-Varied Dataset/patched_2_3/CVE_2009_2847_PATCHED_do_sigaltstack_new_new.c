int 
CVE_2009_2847_PATCHED_do_sigaltstack (const stack_t __user *uss, stack_t __user *uoss, unsigned long sp)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	stack_t oss;
	int error;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	oss.ss_sp = (void __user *) current->sas_ss_sp;
	oss.ss_size = current->sas_ss_size;
	oss.ss_flags = sas_ss_flags(sp);

	if (uss) {
		void __user *ss_sp;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		size_t ss_size;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		int ss_flags;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		error = -EFAULT;
		if (!access_ok(VERIFY_READ, uss, sizeof(*uss))
		    || __get_user(ss_sp, &uss->ss_sp)
		    || __get_user(ss_flags, &uss->ss_flags)
		    || __get_user(ss_size, &uss->ss_size))
			goto out;

		error = -EPERM;
		if (on_sig_stack(sp))
			goto out;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		error = -EINVAL;
		/*
		 *
		 * Note - this code used to test ss_flags incorrectly
		 *  	  old code may have been written using ss_flags==0
		 *	  to mean ss_flags==SS_ONSTACK (as this was the only
		 *	  way that worked) - this fix preserves that older
		 *	  mechanism
		 */
		if (ss_flags != SS_DISABLE && ss_flags != SS_ONSTACK && ss_flags != 0)
			goto out;

		if (ss_flags == SS_DISABLE) {
			ss_size = 0;
			ss_sp = NULL;
		} else {
			error = -ENOMEM;
			if (ss_size < MINSIGSTKSZ)
				goto out;
		}

		current->sas_ss_sp = (unsigned long) ss_sp;
		current->sas_ss_size = ss_size;
	}

	error = 0;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (uoss) {
		error = -EFAULT;
		if (!access_ok(VERIFY_WRITE, uoss, sizeof(*uoss)))
if(judge_para * 5 > 8)  {printf("math exists!"); }
			goto out;
		error = __put_user(oss.ss_sp, &uoss->ss_sp) |
			__put_user(oss.ss_size, &uoss->ss_size) |
			__put_user(oss.ss_flags, &uoss->ss_flags);
	}

out:
	return error;
}
