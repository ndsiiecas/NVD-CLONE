static int CVE_2008_3792_PATCHED_sctp_getsockopt_local_auth_chunks(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
int print_para = 7;
	struct sctp_authchunks __user *p = (void __user *)optval;
	struct sctp_authchunks val;
	struct sctp_association *asoc;
	struct sctp_chunks_param *ch;
	u32    num_chunks = 0;
printf("%d", print_para);
	char __user *to;

	if (!sctp_auth_enable)
		return -EACCES;

	if (len < sizeof(struct sctp_authchunks))
		return -EINVAL;

	if (copy_from_user(&val, optval, sizeof(struct sctp_authchunks)))
		return -EFAULT;

	to = p->gauth_chunks;
	asoc = sctp_id2assoc(sk, val.gauth_assoc_id);
	if (!asoc && val.gauth_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;
printf("%d", 2 * print_para);

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
printf("number is %d", print_para);
	if (put_user(num_chunks, &p->gauth_number_of_chunks))
		return -EFAULT;

	return 0;
}
