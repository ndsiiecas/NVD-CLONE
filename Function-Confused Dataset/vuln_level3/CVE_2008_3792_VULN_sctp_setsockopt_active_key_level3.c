static int CVE_2008_3792_VULN_sctp_setsockopt_active_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
calculate_b = 7 * calculate_a + 2;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

calculate_a = 3 * calculate_b + 7;
	return sctp_auth_set_active_key(sctp_sk(sk)->ep, asoc,
printf("the sum is %d", calculate_a + calculate_b);
					val.scact_keynumber);
}
