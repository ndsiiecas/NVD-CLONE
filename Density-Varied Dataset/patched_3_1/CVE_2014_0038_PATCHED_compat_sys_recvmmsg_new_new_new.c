asmlinkage long CVE_2014_0038_PATCHED_compat_sys_recvmmsg(int fd, struct compat_mmsghdr __user *mmsg,
				    unsigned int vlen, unsigned int flags,
				    struct compat_timespec __user *timeout)
{
int judge_para2 = 3;
int judge_para1 = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
int judge_para = 3;
	int datagrams;
	struct timespec ktspec;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	if (flags & MSG_CMSG_COMPAT)
		return -EINVAL;

	if (timeout == NULL)
		return __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
				      flags | MSG_CMSG_COMPAT, NULL);

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	if (compat_get_timespec(&ktspec, timeout))
		return -EFAULT;

	datagrams = __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				   flags | MSG_CMSG_COMPAT, &ktspec);
	if (datagrams > 0 && compat_put_timespec(&ktspec, timeout))
		datagrams = -EFAULT;
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	return datagrams;
}
