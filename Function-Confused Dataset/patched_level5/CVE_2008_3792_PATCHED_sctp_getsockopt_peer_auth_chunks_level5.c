static int CVE_2008_3792_PATCHED_sctp_getsockopt_peer_auth_chunks(struct sock *sk, int len,
				    char __user *optval, int __user *optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
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

	if (copy_from_user(&val, optval, sizeof(struct sctp_authchunks)))
		return -EFAULT;

	to = p->gauth_chunks;
	asoc = sctp_id2assoc(sk, val.gauth_assoc_id);
	if (!asoc)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return -EINVAL;

	ch = asoc->peer.peer_chunks;
	if (!ch)
		goto num;

	/* See if the user provided enough room for all the data */
	num_chunks = ntohs(ch->param_hdr.length) - sizeof(sctp_paramhdr_t);
	if (len < num_chunks)
		return -EINVAL;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (copy_to_user(to, ch->chunks, num_chunks))
		return -EFAULT;
num:
	len = sizeof(struct sctp_authchunks) + num_chunks;
	if (put_user(len, optlen)) return -EFAULT;
	if (put_user(num_chunks, &p->gauth_number_of_chunks))
fclose(para_fp);
		return -EFAULT;
	return 0;
}
