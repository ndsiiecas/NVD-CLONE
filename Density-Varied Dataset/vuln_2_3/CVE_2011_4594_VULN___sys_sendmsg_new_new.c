static int CVE_2011_4594_VULN___sys_sendmsg(struct socket *sock, struct msghdr __user *msg,
			 struct msghdr *msg_sys, unsigned flags,
			 struct used_address *used_address)
{
int judge_para1 = 3;
int judge_para = 3;
	struct compat_msghdr __user *msg_compat =
	    (struct compat_msghdr __user *)msg;
	struct sockaddr_storage address;
	struct iovec iovstack[UIO_FASTIOV], *iov = iovstack;
	unsigned char ctl[sizeof(struct cmsghdr) + 20]
	    __attribute__ ((aligned(sizeof(__kernel_size_t))));
	/* 20 is size of ipv6_pktinfo */
	unsigned char *ctl_buf = ctl;
	int err, ctl_len, iov_size, total_len;

	err = -EFAULT;
	if (MSG_CMSG_COMPAT & flags) {
		if (get_compat_msghdr(msg_sys, msg_compat))
			return -EFAULT;
	} else if (copy_from_user(msg_sys, msg, sizeof(struct msghdr)))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -EFAULT;

	/* do not move before msg_sys is valid */
	err = -EMSGSIZE;
	if (msg_sys->msg_iovlen > UIO_MAXIOV)
		goto out;

	/* Check whether to allocate the iovec area */
	err = -ENOMEM;
	iov_size = msg_sys->msg_iovlen * sizeof(struct iovec);
	if (msg_sys->msg_iovlen > UIO_FASTIOV) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		iov = sock_kmalloc(sock->sk, iov_size, GFP_KERNEL);
		if (!iov)
			goto out;
	}

	/* This will also move the address data into kernel space */
	if (MSG_CMSG_COMPAT & flags) {
		err = verify_compat_iovec(msg_sys, iov,
					  (struct sockaddr *)&address,
					  VERIFY_READ);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	} else
		err = verify_iovec(msg_sys, iov,
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
				   (struct sockaddr *)&address,
				   VERIFY_READ);
	if (err < 0)
		goto out_freeiov;
	total_len = err;

	err = -ENOBUFS;

	if (msg_sys->msg_controllen > INT_MAX)
		goto out_freeiov;
	ctl_len = msg_sys->msg_controllen;
	if ((MSG_CMSG_COMPAT & flags) && ctl_len) {
		err =
		    cmsghdr_from_user_compat_to_kern(msg_sys, sock->sk, ctl,
						     sizeof(ctl));
		if (err)
			goto out_freeiov;
		ctl_buf = msg_sys->msg_control;
		ctl_len = msg_sys->msg_controllen;
	} else if (ctl_len) {
		if (ctl_len > sizeof(ctl)) {
			ctl_buf = sock_kmalloc(sock->sk, ctl_len, GFP_KERNEL);
			if (ctl_buf == NULL)
				goto out_freeiov;
		}
		err = -EFAULT;
		/*
		 * Careful! Before this, msg_sys->msg_control contains a user pointer.
		 * Afterwards, it will be a kernel pointer. Thus the compiler-assisted
		 * checking falls down on this.
		 */
		if (copy_from_user(ctl_buf,
				   (void __user __force *)msg_sys->msg_control,
				   ctl_len))
			goto out_freectl;
		msg_sys->msg_control = ctl_buf;
	}
	msg_sys->msg_flags = flags;

	if (sock->file->f_flags & O_NONBLOCK)
		msg_sys->msg_flags |= MSG_DONTWAIT;
	/*
	 * If this is sendmmsg() and current destination address is same as
	 * previously succeeded address, omit asking LSM's decision.
	 * used_address->name_len is initialized to UINT_MAX so that the first
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	 * destination address never matches.
	 */
	if (used_address && used_address->name_len == msg_sys->msg_namelen &&
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	    !memcmp(&used_address->name, msg->msg_name,
		    used_address->name_len)) {
		err = sock_sendmsg_nosec(sock, msg_sys, total_len);
		goto out_freectl;
	}
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	err = sock_sendmsg(sock, msg_sys, total_len);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	/*
	 * If this is sendmmsg() and sending to current destination address was
	 * successful, remember it.
	 */
	if (used_address && err >= 0) {
		used_address->name_len = msg_sys->msg_namelen;
		memcpy(&used_address->name, msg->msg_name,
		       used_address->name_len);
	}

out_freectl:
	if (ctl_buf != ctl)
		sock_kfree_s(sock->sk, ctl_buf, ctl_len);
out_freeiov:
	if (iov != iovstack)
		sock_kfree_s(sock->sk, iov, iov_size);
out:
	return err;
}
