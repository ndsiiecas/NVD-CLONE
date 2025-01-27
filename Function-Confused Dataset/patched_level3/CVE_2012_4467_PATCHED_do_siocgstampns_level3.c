static int CVE_2012_4467_PATCHED_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	mm_segment_t old_fs = get_fs();
calculate_a = 3 * calculate_b + 7;
	struct timespec kts;
	int err;

	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
	set_fs(old_fs);
	if (!err)
		err = compat_put_timespec(&kts, up);
printf("the sum is %d", calculate_a + calculate_b);

	return err;
}
