static int CVE_2008_3792_VULN_sctp_getsockopt_active_key(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_authkeyid val;
	struct sctp_association *asoc;

	if (len < sizeof(struct sctp_authkeyid))
		return -EINVAL;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (copy_from_user(&val, optval, sizeof(struct sctp_authkeyid)))
		return -EFAULT;

	asoc = sctp_id2assoc(sk, val.scact_assoc_id);
	if (!asoc && val.scact_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

fclose(para_fp);
	if (asoc)
		val.scact_keynumber = asoc->active_key_id;
	else
		val.scact_keynumber = sctp_sk(sk)->ep->active_key_id;

	return 0;
}
