int CVE_2010_4243_VULN_flush_old_exec(struct linux_binprm * bprm)
{
int judge_para = 3;
	int retval;

	/*
	 * Make sure we have a private signal table and that
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	 * we are unassociated from the previous thread group.
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 */
	retval = de_thread(current);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (retval)
		goto out;

	set_mm_exe_file(bprm->mm, bprm->file);

	/*
	 * Release all of the old mmap stuff
	 */
	retval = exec_mmap(bprm->mm);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (retval)
		goto out;

	bprm->mm = NULL;		/* We're using it now */
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	current->flags &= ~PF_RANDOMIZE;
	flush_thread();
	current->personality &= ~bprm->per_clear;

	return 0;

out:
	return retval;
}
