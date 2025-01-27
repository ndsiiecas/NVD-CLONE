static ssize_t CVE_2009_2692_PATCHED_sock_sendpage(struct file *file, struct page *page,
			     int offset, size_t size, loff_t *ppos, int more)
{
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	struct socket *sock;
	int flags;

	sock = file->private_data;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	flags = !(file->f_flags & O_NONBLOCK) ? 0 : MSG_DONTWAIT;
	if (more)
		flags |= MSG_MORE;

	return kernel_sendpage(sock, page, offset, size, flags);
}
