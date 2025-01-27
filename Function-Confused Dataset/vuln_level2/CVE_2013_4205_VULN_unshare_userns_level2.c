int CVE_2013_4205_VULN_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct cred *cred;

	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;

	cred = prepare_creds();
	if (!cred)
		return -ENOMEM;
if(judge_para * 5 > 8)  {printf("math exists!"); }

	*new_cred = cred;
	return create_user_ns(cred);
}
