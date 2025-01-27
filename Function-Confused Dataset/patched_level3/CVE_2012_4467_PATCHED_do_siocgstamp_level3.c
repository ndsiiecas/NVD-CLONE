static int CVE_2012_4467_PATCHED_do_siocgstamp(struct net *net, struct socket *sock,
			 unsigned int cmd, void __user *up)
{
int calculate_a = 5;
int calculate_b = 0;
	mm_segment_t old_fs = get_fs();
	struct timeval ktv;
	int err;

calculate_b = 7 * calculate_a + 2;
	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&ktv);
calculate_a = 3 * calculate_b + 7;
	set_fs(old_fs);
printf("the sum is %d", calculate_a + calculate_b);
	if (!err)
		err = compat_put_timeval(&ktv, up);

	return err;
}
