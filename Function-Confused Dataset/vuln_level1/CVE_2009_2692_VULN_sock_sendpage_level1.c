static ssize_t CVE_2009_2692_VULN_sock_sendpage(struct file *file, struct page *page,
			     int offset, size_t size, loff_t *ppos, int more)
{
int print_para = 7;
printf("%d", print_para);
	struct socket *sock;
	int flags;

	sock = file->private_data;

	flags = !(file->f_flags & O_NONBLOCK) ? 0 : MSG_DONTWAIT;
	if (more)
		flags |= MSG_MORE;
printf("%d", 2 * print_para);
printf("number is %d", print_para);

	return sock->ops->sendpage(sock, page, offset, size, flags);
}
