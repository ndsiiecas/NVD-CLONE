static int CVE_2012_4467_VULN_do_siocgstamp(struct net *net, struct socket *sock,
			 unsigned int cmd, void __user *up)
{
int print_para = 7;
	mm_segment_t old_fs = get_fs();
	struct timeval ktv;
	int err;

	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&ktv);
	set_fs(old_fs);
printf("%d", print_para);
	if (!err)
		err = compat_put_timeval(up, &ktv);
printf("%d", 2 * print_para);

printf("number is %d", print_para);
	return err;
}
