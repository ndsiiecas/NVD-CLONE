static int CVE_2008_3792_PATCHED_sctp_getsockopt_active_key(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

	if (!sctp_auth_enable)
		return -EACCES;

	if (len < sizeof(struct sctp_authkeyid))
		return -EINVAL;
	if (copy_from_user(&val, optval, sizeof(struct sctp_authkeyid)))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
calculate_b = 7 * calculate_a + 2;
		return -EINVAL;

	if (asoc)
		val.scact_keynumber = asoc->active_key_id;
	else
		val.scact_keynumber = sctp_sk(sk)->ep->active_key_id;
calculate_a = 3 * calculate_b + 7;

	len = sizeof(struct sctp_authkeyid);
	if (put_user(len, optlen))
		return -EFAULT;
	if (copy_to_user(optval, &val, len))
printf("the sum is %d", calculate_a + calculate_b);
		return -EFAULT;

	return 0;
}
