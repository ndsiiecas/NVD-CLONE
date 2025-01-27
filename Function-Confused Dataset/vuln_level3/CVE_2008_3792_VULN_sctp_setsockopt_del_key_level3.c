static int CVE_2008_3792_VULN_sctp_setsockopt_del_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int calculate_a = 5;
int calculate_b = 0;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

calculate_b = 7 * calculate_a + 2;
	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
calculate_a = 3 * calculate_b + 7;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
printf("the sum is %d", calculate_a + calculate_b);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

	return sctp_auth_del_key_id(sctp_sk(sk)->ep, asoc,
				    val.scact_keynumber);

}
