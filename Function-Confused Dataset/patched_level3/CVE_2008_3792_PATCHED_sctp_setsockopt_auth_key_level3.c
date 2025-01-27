static int CVE_2008_3792_PATCHED_sctp_setsockopt_auth_key(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_authkey *authkey;
	struct sctp_association *asoc;
	int ret;

	if (!sctp_auth_enable)
calculate_b = 7 * calculate_a + 2;
		return -EACCES;

	if (optlen <= sizeof(struct sctp_authkey))
		return -EINVAL;
calculate_a = 3 * calculate_b + 7;

	authkey = kmalloc(optlen, GFP_KERNEL);
	if (!authkey)
		return -ENOMEM;

	if (copy_from_user(authkey, optval, optlen)) {
printf("the sum is %d", calculate_a + calculate_b);
		ret = -EFAULT;
		goto out;
	}

	asoc = sctp_id2assoc(sk, authkey->sca_assoc_id);
	if (!asoc && authkey->sca_assoc_id && sctp_style(sk, UDP)) {
		ret = -EINVAL;
		goto out;
	}

	ret = sctp_auth_set_key(sctp_sk(sk)->ep, asoc, authkey);
out:
	kfree(authkey);
	return ret;
}
