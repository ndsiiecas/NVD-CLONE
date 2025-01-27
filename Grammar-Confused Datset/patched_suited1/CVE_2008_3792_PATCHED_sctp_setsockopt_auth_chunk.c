static int CVE_2008_3792_PATCHED_sctp_setsockopt_auth_chunk(struct sock *sk,
				    char __user *optval,
				    int optlen)
{
	struct sctp_authchunk val;

	if (!sctp_auth_enable)
		return -EACCES;

	if (optlen != sizeof(struct sctp_authchunk))
		return -EINVAL;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (copy_from_user(&val, optval, optlen))
		return -EFAULT;

	switch (val.sauth_chunk) {
		case SCTP_CID_INIT:
		case SCTP_CID_INIT_ACK:
		case SCTP_CID_SHUTDOWN_COMPLETE:
		case SCTP_CID_AUTH:
			return -EINVAL;
	}

	/* add this chunk id to the endpoint */
	return sctp_auth_ep_add_chunkid(sctp_sk(sk)->ep, val.sauth_chunk);
}
