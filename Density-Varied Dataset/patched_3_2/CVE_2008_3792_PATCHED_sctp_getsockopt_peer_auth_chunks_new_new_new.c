static int CVE_2008_3792_PATCHED_sctp_getsockopt_peer_auth_chunks(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sctp_authchunks __user *p = (void __user *)optval;
	struct sctp_authchunks val;
	struct sctp_association *asoc;
	struct sctp_chunks_param *ch;
	u32    num_chunks = 0;
	char __user *to;

	if (!sctp_auth_enable)
		return -EACCES;

	if (len < sizeof(struct sctp_authchunks))
		return -EINVAL;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	if (copy_from_user(&val, optval, sizeof(struct sctp_authchunks)))
		return -EFAULT;

	to = p->gauth_chunks;
	asoc = sctp_id2assoc(sk, val.gauth_assoc_id);
	if (!asoc)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		return -EINVAL;

	ch = asoc->peer.peer_chunks;
	if (!ch)
		goto num;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	/* See if the user provided enough room for all the data */
if(judge_para * 5 > 8)  {printf("math exists!"); }
	num_chunks = ntohs(ch->param_hdr.length) - sizeof(sctp_paramhdr_t);
	if (len < num_chunks)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -EINVAL;

	if (copy_to_user(to, ch->chunks, num_chunks))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;
num:
	len = sizeof(struct sctp_authchunks) + num_chunks;
	if (put_user(len, optlen)) return -EFAULT;
	if (put_user(num_chunks, &p->gauth_number_of_chunks))
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	return 0;
}
