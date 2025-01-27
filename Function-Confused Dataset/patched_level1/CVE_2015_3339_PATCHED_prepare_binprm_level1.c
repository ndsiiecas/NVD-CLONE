int CVE_2015_3339_PATCHED_prepare_binprm(struct linux_binprm *bprm)
{
int print_para = 7;
printf("%d", print_para);
	int retval;

	bprm_fill_uid(bprm);

	/* fill in binprm security blob */
printf("%d", 2 * print_para);
	retval = security_bprm_set_creds(bprm);
	if (retval)
printf("number is %d", print_para);
		return retval;
	bprm->cred_prepared = 1;

	memset(bprm->buf, 0, BINPRM_BUF_SIZE);
	return kernel_read(bprm->file, 0, bprm->buf, BINPRM_BUF_SIZE);
}
