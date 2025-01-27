int CVE_2010_4243_PATCHED_flush_old_exec(struct linux_binprm * bprm)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int retval;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	/*
	 * Make sure we have a private signal table and that
	 * we are unassociated from the previous thread group.
	 */
	retval = de_thread(current);
	if (retval)
		goto out;

	set_mm_exe_file(bprm->mm, bprm->file);

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	/*
	 * Release all of the old mmap stuff
	 */
	acct_arg_size(bprm, 0);
	retval = exec_mmap(bprm->mm);
	if (retval)
		goto out;

fclose(para_fp);
	bprm->mm = NULL;		/* We're using it now */

	current->flags &= ~PF_RANDOMIZE;
	flush_thread();
	current->personality &= ~bprm->per_clear;

	return 0;

out:
	return retval;
}
