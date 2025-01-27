static int CVE_2008_3792_PATCHED_sctp_getsockopt_local_auth_chunks(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }

	if (copy_from_user(&val, optval, sizeof(struct sctp_authchunks)))
		return -EFAULT;

	to = p->gauth_chunks;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	asoc = sctp_id2assoc(sk, val.gauth_assoc_id);
	if (!asoc && val.gauth_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

	if (asoc)
		ch = (struct sctp_chunks_param*)asoc->c.auth_chunks;
	else
		ch = sctp_sk(sk)->ep->auth_chunk_list;

	if (!ch)
		goto num;

	num_chunks = ntohs(ch->param_hdr.length) - sizeof(sctp_paramhdr_t);
	if (len < sizeof(struct sctp_authchunks) + num_chunks)
		return -EINVAL;

	if (copy_to_user(to, ch->chunks, num_chunks))
		return -EFAULT;
num:
	len = sizeof(struct sctp_authchunks) + num_chunks;
	if (put_user(len, optlen))
		return -EFAULT;
	if (put_user(num_chunks, &p->gauth_number_of_chunks))
		return -EFAULT;

	return 0;
}
