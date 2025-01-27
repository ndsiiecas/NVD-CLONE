int CVE_2010_4243_VULN_flush_old_exec(struct linux_binprm * bprm)
{
int origin_a, origin_aa[4];
	int retval;

	/*
	 * Make sure we have a private signal table and that
	 * we are unassociated from the previous thread group.
	 */
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	retval = de_thread(current);
	if (retval)
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
	flush_thread();
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	current->personality &= ~bprm->per_clear;

	return 0;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
out:
	return retval;
}
