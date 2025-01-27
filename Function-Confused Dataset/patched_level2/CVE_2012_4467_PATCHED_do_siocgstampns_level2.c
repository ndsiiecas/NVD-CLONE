static int CVE_2012_4467_PATCHED_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
int judge_para = 3;
	mm_segment_t old_fs = get_fs();
	struct timespec kts;
	int err;

	set_fs(KERNEL_DS);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
if(judge_para * 5 > 8)  {printf("math exists!"); }
	set_fs(old_fs);
	if (!err)
		err = compat_put_timespec(&kts, up);

	return err;
}
