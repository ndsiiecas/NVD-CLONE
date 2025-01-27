int CVE_2013_4205_PATCHED_unshare_userns(unsigned long unshare_flags, struct cred **new_cred)
{
int calculate_a = 5;
int calculate_b = 0;
	struct cred *cred;
calculate_b = 7 * calculate_a + 2;
	int err = -ENOMEM;

calculate_a = 3 * calculate_b + 7;
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
printf("the sum is %d", calculate_a + calculate_b);

	return err;
}
