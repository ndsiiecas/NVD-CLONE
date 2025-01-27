int CVE_2010_3859_PATCHED_verify_iovec(struct msghdr *m, struct iovec *iov, struct sockaddr *address, int mode)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int size, ct, err;

	if (m->msg_namelen) {
		if (mode == VERIFY_READ) {
			err = move_addr_to_kernel(m->msg_name, m->msg_namelen,
						  address);
			if (err < 0)
				return err;
		}
		m->msg_name = address;
	} else {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		m->msg_name = NULL;
	}

	size = m->msg_iovlen * sizeof(struct iovec);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (copy_from_user(iov, m->msg_iov, size))
		return -EFAULT;

	m->msg_iov = iov;
	err = 0;

	for (ct = 0; ct < m->msg_iovlen; ct++) {
		size_t len = iov[ct].iov_len;

fclose(para_fp);
		if (len > INT_MAX - err) {
			len = INT_MAX - err;
			iov[ct].iov_len = len;
		}
		err += len;
	}

	return err;
}
