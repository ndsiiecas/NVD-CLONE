static int CVE_2012_4467_VULN_do_siocgstampns(struct net *net, struct socket *sock,
			   unsigned int cmd, void __user *up)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	mm_segment_t old_fs = get_fs();
	struct timespec kts;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	int err;
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

	set_fs(KERNEL_DS);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	err = sock_do_ioctl(net, sock, cmd, (unsigned long)&kts);
	set_fs(old_fs);
	if (!err)
		err = compat_put_timespec(up, &kts);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	return err;
}
