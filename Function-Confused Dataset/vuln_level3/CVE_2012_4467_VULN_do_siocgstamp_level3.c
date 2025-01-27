static int CVE_2012_4467_VULN_do_siocgstamp(struct net *net, struct socket *sock,
			 unsigned int cmd, void __user *up)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	mm_segment_t old_fs = get_fs();
	struct timeval ktv;
	int err;

	set_fs(KERNEL_DS);
calculate_a = 3 * calculate_b + 7;
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&ktv);
	set_fs(old_fs);
	if (!err)
printf("the sum is %d", calculate_a + calculate_b);
		err = compat_put_timeval(up, &ktv);

	return err;
}
