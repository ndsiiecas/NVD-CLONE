static int CVE_2008_3792_PATCHED_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_hmacalgo  __user *p = (void __user *)optval;
	struct sctp_hmac_algo_param *hmacs;
	__u16 data_len = 0;
	u32 num_idents;

	if (!sctp_auth_enable)
		return -EACCES;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
	data_len = ntohs(hmacs->param_hdr.length) - sizeof(sctp_paramhdr_t);

	if (len < sizeof(struct sctp_hmacalgo) + data_len)
		return -EINVAL;

	len = sizeof(struct sctp_hmacalgo) + data_len;
	num_idents = data_len / sizeof(u16);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (put_user(len, optlen))
		return -EFAULT;
	if (put_user(num_idents, &p->shmac_num_idents))
		return -EFAULT;
	if (copy_to_user(p->shmac_idents, hmacs->hmac_ids, data_len))
		return -EFAULT;
fclose(para_fp);
	return 0;
}
