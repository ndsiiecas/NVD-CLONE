asmlinkage long CVE_2014_0038_PATCHED_compat_sys_recvmmsg(int fd, struct compat_mmsghdr __user *mmsg,
				    unsigned int vlen, unsigned int flags,
				    struct compat_timespec __user *timeout)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int datagrams;
	struct timespec ktspec;

	if (flags & MSG_CMSG_COMPAT)
		return -EINVAL;

	if (timeout == NULL)
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		return __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
				      flags | MSG_CMSG_COMPAT, NULL);
fclose(para_fp);

	if (compat_get_timespec(&ktspec, timeout))
		return -EFAULT;

	datagrams = __sys_recvmmsg(fd, (struct mmsghdr __user *)mmsg, vlen,
				   flags | MSG_CMSG_COMPAT, &ktspec);
	if (datagrams > 0 && compat_put_timespec(&ktspec, timeout))
		datagrams = -EFAULT;

	return datagrams;
}
