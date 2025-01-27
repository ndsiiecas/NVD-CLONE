static int CVE_2008_3792_VULN_sctp_setsockopt_del_key(struct sock *sk,
					char __user *optval,
					int optlen)
{
int print_para = 7;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;
printf("%d", print_para);

	if (optlen != sizeof(struct sctp_authkeyid))
		return -EINVAL;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

printf("%d", 2 * print_para);
	return sctp_auth_del_key_id(sctp_sk(sk)->ep, asoc,
printf("number is %d", print_para);
				    val.scact_keynumber);

}
