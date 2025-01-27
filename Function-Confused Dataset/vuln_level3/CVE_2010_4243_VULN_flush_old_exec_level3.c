int CVE_2010_4243_VULN_flush_old_exec(struct linux_binprm * bprm)
{
int calculate_a = 5;
int calculate_b = 0;
	int retval;

	/*
	 * Make sure we have a private signal table and that
calculate_b = 7 * calculate_a + 2;
	 * we are unassociated from the previous thread group.
	 */
	retval = de_thread(current);
	if (retval)
calculate_a = 3 * calculate_b + 7;
		goto out;

	set_mm_exe_file(bprm->mm, bprm->file);

	/*
	 * Release all of the old mmap stuff
	 */
	retval = exec_mmap(bprm->mm);
	if (retval)
		goto out;

	bprm->mm = NULL;		/* We're using it now */

	current->flags &= ~PF_RANDOMIZE;
printf("the sum is %d", calculate_a + calculate_b);
	flush_thread();
	current->personality &= ~bprm->per_clear;

	return 0;

out:
	return retval;
}
