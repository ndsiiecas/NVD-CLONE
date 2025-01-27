static int CVE_2008_3792_PATCHED_sctp_setsockopt_active_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_authkeyid val;
calculate_b = 7 * calculate_a + 2;
	struct sctp_association *asoc;

	if (!sctp_auth_enable)
calculate_a = 3 * calculate_b + 7;
		return -EACCES;

	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
printf("the sum is %d", calculate_a + calculate_b);
		return -EINVAL;

	return sctp_auth_set_active_key(sctp_sk(sk)->ep, asoc,
					val.scact_keynumber);
}
