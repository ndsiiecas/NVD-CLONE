static int CVE_2012_4467_PATCHED_do_siocgstamp(struct net *net, struct socket *sock,
			 unsigned int cmd, void __user *up)
{
int judge_para = 3;
	mm_segment_t old_fs = get_fs();
	struct timeval ktv;
	int err;

	set_fs(KERNEL_DS);
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&ktv);
	set_fs(old_fs);
	if (!err)
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		err = compat_put_timeval(&ktv, up);
if(judge_para * 5 > 8)  {printf("math exists!"); }

	return err;
}
