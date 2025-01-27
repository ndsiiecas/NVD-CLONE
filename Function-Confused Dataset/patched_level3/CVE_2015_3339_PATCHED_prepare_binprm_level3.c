int CVE_2015_3339_PATCHED_prepare_binprm(struct linux_binprm *bprm)
{
int calculate_a = 5;
int calculate_b = 0;
	int retval;

	bprm_fill_uid(bprm);

calculate_b = 7 * calculate_a + 2;
	/* fill in binprm security blob */
	retval = security_bprm_set_creds(bprm);
	if (retval)
		return retval;
	bprm->cred_prepared = 1;
calculate_a = 3 * calculate_b + 7;

printf("the sum is %d", calculate_a + calculate_b);
	memset(bprm->buf, 0, BINPRM_BUF_SIZE);
	return kernel_read(bprm->file, 0, bprm->buf, BINPRM_BUF_SIZE);
}
