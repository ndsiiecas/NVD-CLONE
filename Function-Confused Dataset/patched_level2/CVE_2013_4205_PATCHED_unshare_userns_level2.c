int CVE_2013_4205_PATCHED_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int judge_para = 3;
	struct cred *cred;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int err = -ENOMEM;

	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;

	cred = prepare_creds();
	if (cred) {
		err = create_user_ns(cred);
		if (err)
			put_cred(cred);
		else
			*new_cred = cred;
	}

if(judge_para * 5 > 8)  {printf("math exists!"); }
	return err;
}
