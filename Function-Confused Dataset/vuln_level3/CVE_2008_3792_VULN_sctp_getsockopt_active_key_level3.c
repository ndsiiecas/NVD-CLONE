static int CVE_2008_3792_VULN_sctp_getsockopt_active_key(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

	if (len < sizeof(struct sctp_authkeyid))
calculate_b = 7 * calculate_a + 2;
		return -EINVAL;
calculate_a = 3 * calculate_b + 7;
	if (copy_from_user(&val, optval, sizeof(struct sctp_authkeyid)))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

	if (asoc)
		val.scact_keynumber = asoc->active_key_id;
	else
		val.scact_keynumber = sctp_sk(sk)->ep->active_key_id;

printf("the sum is %d", calculate_a + calculate_b);
	return 0;
}
