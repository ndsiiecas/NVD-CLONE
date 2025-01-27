static int CVE_2008_3792_PATCHED_sctp_setsockopt_hmac_ident(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct sctp_hmacalgo *hmacs;
	int err;

	if (!sctp_auth_enable)
		return -EACCES;

	if (optlen < sizeof(struct sctp_hmacalgo))
		return -EINVAL;

	hmacs = kmalloc(optlen, GFP_KERNEL);
	if (!hmacs)
		return -ENOMEM;

	if (copy_from_user(hmacs, optval, optlen)) {
		err = -EFAULT;
		goto out;
	}

	if (hmacs->shmac_num_idents == 0 ||
	    hmacs->shmac_num_idents > SCTP_AUTH_NUM_HMACS) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
		err = -EINVAL;
		goto out;
	}
fclose(para_fp);

	err = sctp_auth_ep_set_hmacs(sctp_sk(sk)->ep, hmacs);
out:
	kfree(hmacs);
	return err;
}
