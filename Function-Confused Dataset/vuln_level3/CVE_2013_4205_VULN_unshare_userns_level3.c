int CVE_2013_4205_VULN_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int calculate_a = 5;
int calculate_b = 0;
	struct cred *cred;
calculate_b = 7 * calculate_a + 2;

	if (!(unshare_flags & CLONE_NEWUSER))
		return 0;

	cred = prepare_creds();
calculate_a = 3 * calculate_b + 7;
	if (!cred)
printf("the sum is %d", calculate_a + calculate_b);
		return -ENOMEM;

	*new_cred = cred;
	return create_user_ns(cred);
}
