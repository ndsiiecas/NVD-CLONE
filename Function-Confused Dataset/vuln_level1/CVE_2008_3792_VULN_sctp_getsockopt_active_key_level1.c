static int CVE_2008_3792_VULN_sctp_getsockopt_active_key(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int print_para = 7;
	struct sctp_authkeyid val;
printf("%d", print_para);
	struct sctp_association *asoc;

	if (len < sizeof(struct sctp_authkeyid))
		return -EINVAL;
	if (copy_from_user(&val, optval, sizeof(struct sctp_authkeyid)))
		return -EFAULT;

printf("%d", 2 * print_para);
	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
printf("number is %d", print_para);
		return -EINVAL;

	if (asoc)
		val.scact_keynumber = asoc->active_key_id;
	else
		val.scact_keynumber = sctp_sk(sk)->ep->active_key_id;

	return 0;
}
