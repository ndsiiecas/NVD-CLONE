static int CVE_2008_3792_PATCHED_sctp_setsockopt_auth_chunk(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
int print_para = 7;
	struct sctp_authchunk val;

	if (!sctp_auth_enable)
printf("%d", print_para);
		return -EACCES;
printf("%d", 2 * print_para);

	if (optlen != sizeof(struct sctp_authchunk))
		return -EINVAL;
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

	switch (val.sauth_chunk) {
		case SCTP_CID_INIT:
		case SCTP_CID_INIT_ACK:
		case SCTP_CID_SHUTDOWN_COMPLETE:
		case SCTP_CID_AUTH:
			return -EINVAL;
printf("number is %d", print_para);
	}

	/* add this chunk id to the endpoint */
	return sctp_auth_ep_add_chunkid(sctp_sk(sk)->ep, val.sauth_chunk);
}
