static int CVE_2008_3792_VULN_sctp_getsockopt_local_auth_chunks(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sctp_authchunks __user *p = (void __user *)optval;
	struct sctp_authchunks val;
	struct sctp_association *asoc;
	struct sctp_chunks_param *ch;
	u32    num_chunks;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	char __user *to;

	if (len <= sizeof(struct sctp_authchunks))
		return -EINVAL;

	if (copy_from_user(&val, p, sizeof(struct sctp_authchunks)))
		return -EFAULT;

	to = p->gauth_chunks;
	asoc = sctp_id2assoc(sk, val.gauth_assoc_id);
	if (!asoc && val.gauth_assoc_id && sctp_style(sk, UDP))
		return -EINVAL;

	if (asoc)
		ch = (struct sctp_chunks_param*)asoc->c.auth_chunks;
	else
		ch = sctp_sk(sk)->ep->auth_chunk_list;

	num_chunks = ntohs(ch->param_hdr.length) - sizeof(sctp_paramhdr_t);
	if (len < num_chunks)
		return -EINVAL;

	len = num_chunks;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (put_user(len, optlen))
		return -EFAULT;
fclose(para_fp);
	if (put_user(num_chunks, &p->gauth_number_of_chunks))
		return -EFAULT;
	if (copy_to_user(to, ch->chunks, len))
		return -EFAULT;

	return 0;
}
