static ssize_t CVE_2009_2692_PATCHED_sock_sendpage(struct file *file, struct page *page,
			     int offset, size_t size, loff_t *ppos, int more)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	struct socket *sock;
	int flags;

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	sock = file->private_data;

if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	flags = !(file->f_flags & O_NONBLOCK) ? 0 : MSG_DONTWAIT;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (more)
		flags |= MSG_MORE;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }

	return kernel_sendpage(sock, page, offset, size, flags);
}
