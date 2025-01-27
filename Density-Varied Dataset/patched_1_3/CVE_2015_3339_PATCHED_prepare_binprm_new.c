int CVE_2015_3339_PATCHED_prepare_binprm(struct linux_binprm *bprm)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int retval;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	bprm_fill_uid(bprm);

if(judge_para * 5 > 8)  {printf("math exists!"); }
	/* fill in binprm security blob */
	retval = security_bprm_set_creds(bprm);
	if (retval)
		return retval;
	bprm->cred_prepared = 1;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	memset(bprm->buf, 0, BINPRM_BUF_SIZE);
	return kernel_read(bprm->file, 0, bprm->buf, BINPRM_BUF_SIZE);
}
