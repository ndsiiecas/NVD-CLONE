int CVE_2010_3859_PATCHED_verify_iovec(struct msghdr *m, struct iovec *iov, struct sockaddr *address, int mode)
{
int judge_para1 = 3;
int judge_para = 3;
	int size, ct, err;

	if (m->msg_namelen) {
		if (mode == VERIFY_READ) {
			err = move_addr_to_kernel(m->msg_name, m->msg_namelen,
						  address);
			if (err < 0)
				return err;
		}
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		m->msg_name = address;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	} else {
		m->msg_name = NULL;
	}

	size = m->msg_iovlen * sizeof(struct iovec);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	if (copy_from_user(iov, m->msg_iov, size))
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		return -EFAULT;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	m->msg_iov = iov;
	err = 0;

	for (ct = 0; ct < m->msg_iovlen; ct++) {
		size_t len = iov[ct].iov_len;

		if (len > INT_MAX - err) {
			len = INT_MAX - err;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			iov[ct].iov_len = len;
		}
		err += len;
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	return err;
}
