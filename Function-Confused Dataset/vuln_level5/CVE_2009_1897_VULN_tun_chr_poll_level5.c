static unsigned int CVE_2009_1897_VULN_tun_chr_poll(struct file *file, poll_table * wait)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct tun_file *tfile = file->private_data;
	struct tun_struct *tun = __tun_get(tfile);
	struct sock *sk = tun->sk;
	unsigned int mask = 0;

	if (!tun)
		return POLLERR;

	DBG(KERN_INFO "%s: CVE_2009_1897_VULN_tun_chr_poll\n", tun->dev->name);

	poll_wait(file, &tun->socket.wait, wait);

	if (!skb_queue_empty(&tun->readq))
		mask |= POLLIN | POLLRDNORM;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (sock_writeable(sk) ||
	    (!test_and_set_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags) &&
	     sock_writeable(sk)))
		mask |= POLLOUT | POLLWRNORM;

	if (tun->dev->reg_state != NETREG_REGISTERED)
		mask = POLLERR;
fclose(para_fp);

	tun_put(tun);
	return mask;
}
