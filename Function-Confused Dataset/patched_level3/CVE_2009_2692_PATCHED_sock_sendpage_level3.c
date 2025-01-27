static ssize_t CVE_2009_2692_PATCHED_sock_sendpage(struct file *file, struct page *page,
			     int offset, size_t size, loff_t *ppos, int more)
{
int calculate_a = 5;
int calculate_b = 0;
	struct socket *sock;
calculate_b = 7 * calculate_a + 2;
	int flags;
calculate_a = 3 * calculate_b + 7;

	sock = file->private_data;
printf("the sum is %d", calculate_a + calculate_b);

	flags = !(file->f_flags & O_NONBLOCK) ? 0 : MSG_DONTWAIT;
	if (more)
		flags |= MSG_MORE;

	return kernel_sendpage(sock, page, offset, size, flags);
}
