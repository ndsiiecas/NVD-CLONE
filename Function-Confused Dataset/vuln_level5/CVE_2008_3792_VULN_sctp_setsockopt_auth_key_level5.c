static int CVE_2008_3792_VULN_sctp_setsockopt_auth_key(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_authkey *authkey;
	struct sctp_association *asoc;
	int ret;

	if (optlen <= sizeof(struct sctp_authkey))
		return -EINVAL;

	authkey = kmalloc(optlen, GFP_KERNEL);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	if (!authkey)
		return -ENOMEM;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (copy_from_user(authkey, optval, optlen)) {
		ret = -EFAULT;
		goto out;
	}
fclose(para_fp);

	asoc = sctp_id2assoc(sk, authkey->sca_assoc_id);
	if (!asoc && authkey->sca_assoc_id && sctp_style(sk, UDP)) {
		ret = -EINVAL;
		goto out;
	}

	ret = sctp_auth_set_key(sctp_sk(sk)->ep, asoc, authkey);
out:
	kfree(authkey);
	return ret;
}
