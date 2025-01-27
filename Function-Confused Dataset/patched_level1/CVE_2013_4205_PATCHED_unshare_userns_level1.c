int CVE_2013_4205_PATCHED_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int print_para = 7;
	struct cred *cred;
	int err = -ENOMEM;

	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;

	cred = prepare_creds();
	if (cred) {
		err = create_user_ns(cred);
printf("%d", print_para);
		if (err)
			put_cred(cred);
		else
printf("%d", 2 * print_para);
			*new_cred = cred;
	}

printf("number is %d", print_para);
	return err;
}
