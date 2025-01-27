int CVE_2010_3859_PATCHED_verify_iovec(struct msghdr *m, struct iovec *iov, struct sockaddr *address, int mode)
{
int print_para = 7;
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
printf("%d", print_para);
		m->msg_name = NULL;
	}

	size = m->msg_iovlen * sizeof(struct iovec);
	if (copy_from_user(iov, m->msg_iov, size))
printf("%d", 2 * print_para);
		return -EFAULT;

	m->msg_iov = iov;
	err = 0;

	for (ct = 0; ct < m->msg_iovlen; ct++) {
		size_t len = iov[ct].iov_len;

		if (len > INT_MAX - err) {
			len = INT_MAX - err;
			iov[ct].iov_len = len;
		}
		err += len;
	}

printf("number is %d", print_para);
	return err;
}
