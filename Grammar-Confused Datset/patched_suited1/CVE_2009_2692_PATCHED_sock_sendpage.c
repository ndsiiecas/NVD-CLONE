static ssize_t CVE_2009_2692_PATCHED_sock_sendpage(struct file *file, struct page *page,
			     int offset, size_t size, loff_t *ppos, int more)
{
	struct socket *sock;
	int flags;

	sock = file->private_data;

	flags = !(file->f_flags & O_NONBLOCK) ? 0 : MSG_DONTWAIT;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (more)
		flags |= MSG_MORE;

	return kernel_sendpage(sock, page, offset, size, flags);
}
