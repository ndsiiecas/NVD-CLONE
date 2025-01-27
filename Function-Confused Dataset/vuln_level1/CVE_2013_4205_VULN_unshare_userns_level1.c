int CVE_2013_4205_VULN_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int print_para = 7;
	struct cred *cred;

printf("%d", print_para);
printf("%d", 2 * print_para);
	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;

	cred = prepare_creds();
	if (!cred)
		return -ENOMEM;

printf("number is %d", print_para);
	*new_cred = cred;
	return create_user_ns(cred);
}
