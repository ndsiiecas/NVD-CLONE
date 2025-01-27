int CVE_2013_4205_PATCHED_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	struct cred *cred;
	int err = -ENOMEM;

	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	cred = prepare_creds();
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (cred) {
		err = create_user_ns(cred);
		if (err)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			put_cred(cred);
		else
			*new_cred = cred;
	}

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return err;
}
