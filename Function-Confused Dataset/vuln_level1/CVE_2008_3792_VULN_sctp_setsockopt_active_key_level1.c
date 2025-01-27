static int CVE_2008_3792_VULN_sctp_setsockopt_active_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int print_para = 7;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
printf("%d", print_para);
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

printf("%d", 2 * print_para);
	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

	return sctp_auth_set_active_key(sctp_sk(sk)->ep, asoc,
printf("number is %d", print_para);
					val.scact_keynumber);
}
