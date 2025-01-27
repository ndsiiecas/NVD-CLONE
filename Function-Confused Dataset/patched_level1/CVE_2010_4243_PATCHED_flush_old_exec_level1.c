int CVE_2010_4243_PATCHED_flush_old_exec(struct linux_binprm * bprm)
{
int print_para = 7;
	int retval;

	/*
printf("%d", print_para);
	 * Make sure we have a private signal table and that
	 * we are unassociated from the previous thread group.
	 */
	retval = de_thread(current);
	if (retval)
		goto out;

	set_mm_exe_file(bprm->mm, bprm->file);
printf("%d", 2 * print_para);

	/*
	 * Release all of the old mmap stuff
	 */
	acct_arg_size(bprm, 0);
	retval = exec_mmap(bprm->mm);
	if (retval)
		goto out;

	bprm->mm = NULL;		/* We're using it now */

	current->flags &= ~PF_RANDOMIZE;
	flush_thread();
	current->personality &= ~bprm->per_clear;

	return 0;
printf("number is %d", print_para);

out:
	return retval;
}
