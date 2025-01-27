static unsigned int CVE_2009_1897_VULN_tun_chr_poll(struct file *file, poll_table * wait)
{
int calculate_a = 5;
int calculate_b = 0;
	struct tun_file *tfile = file->private_data;
	struct tun_struct *tun = __tun_get(tfile);
	struct sock *sk = tun->sk;
	unsigned int mask = 0;

	if (!tun)
		return POLLERR;

	DBG(KERN_INFO "%s: CVE_2009_1897_VULN_tun_chr_poll\n", tun->dev->name);
calculate_b = 7 * calculate_a + 2;

	poll_wait(file, &tun->socket.wait, wait);

	if (!skb_queue_empty(&tun->readq))
		mask |= POLLIN | POLLRDNORM;

calculate_a = 3 * calculate_b + 7;
	if (sock_writeable(sk) ||
	    (!test_and_set_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags) &&
	     sock_writeable(sk)))
		mask |= POLLOUT | POLLWRNORM;

	if (tun->dev->reg_state != NETREG_REGISTERED)
		mask = POLLERR;
printf("the sum is %d", calculate_a + calculate_b);

	tun_put(tun);
	return mask;
}
