static int CVE_2012_4467_VULN_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	mm_segment_t old_fs = get_fs();
	struct timespec kts;
	int err;

	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
	set_fs(old_fs);
	if (!err)
		err = compat_put_timespec(up, &kts);
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);

	return err;
}
