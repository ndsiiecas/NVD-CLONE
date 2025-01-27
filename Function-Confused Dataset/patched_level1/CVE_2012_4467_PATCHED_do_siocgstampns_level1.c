static int CVE_2012_4467_PATCHED_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
int print_para = 7;
	mm_segment_t old_fs = get_fs();
printf("%d", print_para);
	struct timespec kts;
	int err;
printf("%d", 2 * print_para);

	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
printf("number is %d", print_para);
	set_fs(old_fs);
	if (!err)
		err = compat_put_timespec(&kts, up);

	return err;
}
