static int CVE_2008_3792_PATCHED_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int print_para = 7;
	struct sctp_hmacalgo  __user *p = (void __user *)optval;
	struct sctp_hmac_algo_param *hmacs;
	__u16 data_len = 0;
printf("%d", print_para);
	u32 num_idents;
printf("%d", 2 * print_para);

	if (!sctp_auth_enable)
		return -EACCES;

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
	data_len = ntohs(hmacs->param_hdr.length) - sizeof(sctp_paramhdr_t);

	if (len < sizeof(struct sctp_hmacalgo) + data_len)
		return -EINVAL;

	len = sizeof(struct sctp_hmacalgo) + data_len;
	num_idents = data_len / sizeof(u16);

printf("number is %d", print_para);
	if (put_user(len, optlen))
		return -EFAULT;
	if (put_user(num_idents, &p->shmac_num_idents))
		return -EFAULT;
	if (copy_to_user(p->shmac_idents, hmacs->hmac_ids, data_len))
		return -EFAULT;
	return 0;
}
