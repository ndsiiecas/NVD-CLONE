asmlinkage long CVE_2014_0038_VULN_compat_sys_recvmmsg(int fd, struct compat_mmsghdr __user *mmsg,
				    unsigned int vlen, unsigned int flags,
				    struct compat_timespec __user *timeout)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	int datagrams;
	struct timespec ktspec;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}

	if (flags & MSG_CMSG_COMPAT)
		return -EINVAL;

	if (COMPAT_USE_64BIT_TIME)
		return __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				      flags | MSG_CMSG_COMPAT,
				      (struct timespec *) timeout);

	if (timeout == NULL)
fclose(para_fp);
		return __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				      flags | MSG_CMSG_COMPAT, NULL);

	if (get_compat_timespec(&ktspec, timeout))
		return -EFAULT;

	datagrams = __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				   flags | MSG_CMSG_COMPAT, &ktspec);
	if (datagrams > 0 && put_compat_timespec(&ktspec, timeout))
		datagrams = -EFAULT;

	return datagrams;
}
