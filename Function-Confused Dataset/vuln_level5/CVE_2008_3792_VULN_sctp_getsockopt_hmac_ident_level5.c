static int CVE_2008_3792_VULN_sctp_getsockopt_hmac_ident(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_hmac_algo_param *hmacs;
	__u16 param_len;

	hmacs = sctp_sk(sk)->ep->auth_hmacs_list;
	param_len = ntohs(hmacs->param_hdr.length);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (len < param_len)
		return -EINVAL;
	if (put_user(len, optlen))
		return -EFAULT;
	if (copy_to_user(optval, hmacs->hmac_ids, len))
		return -EFAULT;
fclose(para_fp);

	return 0;
}
