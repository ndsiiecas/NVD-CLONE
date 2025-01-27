static int CVE_2008_3792_VULN_sctp_setsockopt_auth_chunk(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_authchunk val;

	if (optlen != sizeof(struct sctp_authchunk))
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return -EINVAL;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	switch (val.sauth_chunk) {
		case SCTP_CID_INIT:
		case SCTP_CID_INIT_ACK:
		case SCTP_CID_SHUTDOWN_COMPLETE:
		case SCTP_CID_AUTH:
			return -EINVAL;
fclose(para_fp);
	}

	/* add this chunk id to the endpoint */
	return sctp_auth_ep_add_chunkid(sctp_sk(sk)->ep, val.sauth_chunk);
}
