int CVE_2010_3859_PATCHED_verify_iovec(struct msghdr *m, struct iovec *iov, struct sockaddr *address, int mode)
{
int calculate_a = 5;
int calculate_b = 0;
	int size, ct, err;

calculate_b = 7 * calculate_a + 2;
	if (m->msg_namelen) {
		if (mode == VERIFY_READ) {
			err = move_addr_to_kernel(m->msg_name, m->msg_namelen,
calculate_a = 3 * calculate_b + 7;
						  address);
			if (err < 0)
				return err;
		}
		m->msg_name = address;
	} else {
		m->msg_name = NULL;
	}

	size = m->msg_iovlen * sizeof(struct iovec);
	if (copy_from_user(iov, m->msg_iov, size))
printf("the sum is %d", calculate_a + calculate_b);
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

	return err;
}
