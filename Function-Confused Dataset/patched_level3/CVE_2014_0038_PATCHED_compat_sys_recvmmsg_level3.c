asmlinkage long CVE_2014_0038_PATCHED_compat_sys_recvmmsg(int fd, struct compat_mmsghdr __user *mmsg,
				    unsigned int vlen, unsigned int flags,
				    struct compat_timespec __user *timeout)
{
int calculate_a = 5;
int calculate_b = 0;
	int datagrams;
	struct timespec ktspec;

calculate_b = 7 * calculate_a + 2;
	if (flags & MSG_CMSG_COMPAT)
		return -EINVAL;
calculate_a = 3 * calculate_b + 7;

	if (timeout == NULL)
		return __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				      flags | MSG_CMSG_COMPAT, NULL);

	if (compat_get_timespec(&ktspec, timeout))
		return -EFAULT;

	datagrams = __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				   flags | MSG_CMSG_COMPAT, &ktspec);
	if (datagrams > 0 && compat_put_timespec(&ktspec, timeout))
printf("the sum is %d", calculate_a + calculate_b);
		datagrams = -EFAULT;

	return datagrams;
}
