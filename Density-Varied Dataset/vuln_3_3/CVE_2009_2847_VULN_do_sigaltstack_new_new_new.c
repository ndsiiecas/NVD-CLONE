int 
CVE_2009_2847_VULN_do_sigaltstack (const stack_t __user *uss, stack_t __user *uoss, unsigned long sp)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	stack_t oss;
	int error;

	if (uoss) {
		oss.ss_sp = (void __user *) current->sas_ss_sp;
		oss.ss_size = current->sas_ss_size;
		oss.ss_flags = sas_ss_flags(sp);
	}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

	if (uss) {
		void __user *ss_sp;
		size_t ss_size;
		int ss_flags;

		error = -EFAULT;
		if (!access_ok(VERIFY_READ, uss, sizeof(*uss))
		    || __get_user(ss_sp, &uss->ss_sp)
		    || __get_user(ss_flags, &uss->ss_flags)
		    || __get_user(ss_size, &uss->ss_size))
			goto out;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		error = -EPERM;
		if (on_sig_stack(sp))
			goto out;

		error = -EINVAL;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		/*
		 *
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		 * Note - this code used to test ss_flags incorrectly
		 *  	  old code may have been written using ss_flags==0
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		 *	  to mean ss_flags==SS_ONSTACK (as this was the only
		 *	  way that worked) - this fix preserves that older
		 *	  mechanism
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		 */
		if (ss_flags != SS_DISABLE && ss_flags != SS_ONSTACK && ss_flags != 0)
			goto out;

if(judge_para * 5 > 8)  {printf("math exists!"); }
		if (ss_flags == SS_DISABLE) {
			ss_size = 0;
			ss_sp = NULL;
		} else {
			error = -ENOMEM;
			if (ss_size < MINSIGSTKSZ)
				goto out;
		}

		current->sas_ss_sp = (unsigned long) ss_sp;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		current->sas_ss_size = ss_size;
	}

	if (uoss) {
		error = -EFAULT;
		if (copy_to_user(uoss, &oss, sizeof(oss)))
			goto out;
	}

	error = 0;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
out:
	return error;
}
