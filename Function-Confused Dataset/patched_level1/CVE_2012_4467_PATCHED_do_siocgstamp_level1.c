static int CVE_2012_4467_PATCHED_do_siocgstamp(struct net *net, struct socket *sock,
			 unsigned int cmd, void __user *up)
{
int print_para = 7;
	mm_segment_t old_fs = get_fs();
printf("%d", print_para);
	struct timeval ktv;
	int err;
printf("%d", 2 * print_para);

printf("number is %d", print_para);
	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&ktv);
	set_fs(old_fs);
	if (!err)
		err = compat_put_timeval(&ktv, up);

	return err;
}
