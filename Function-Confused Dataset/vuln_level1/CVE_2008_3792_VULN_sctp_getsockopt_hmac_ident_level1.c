static int CVE_2008_3792_VULN_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int print_para = 7;
	struct sctp_hmac_algo_param *hmacs;
	__u16 param_len;

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
printf("%d", print_para);
	param_len = ntohs(hmacs->param_hdr.length);

	if (len < param_len)
		return -EINVAL;
	if (put_user(len, optlen))
		return -EFAULT;
printf("%d", 2 * print_para);
	if (copy_to_user(optval, hmacs->hmac_ids, len))
		return -EFAULT;
printf("number is %d", print_para);

	return 0;
}
