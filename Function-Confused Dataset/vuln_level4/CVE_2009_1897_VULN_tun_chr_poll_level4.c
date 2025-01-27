static unsigned int CVE_2009_1897_VULN_tun_chr_poll(struct file *file, poll_table * wait)
{
int origin_a, origin_aa[4];
	struct tun_file *tfile = file->private_data;
	struct tun_struct *tun = __tun_get(tfile);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct sock *sk = tun->sk;
	unsigned int mask = 0;

	if (!tun)
		return POLLERR;

	DBG(KERN_INFO "%s: CVE_2009_1897_VULN_tun_chr_poll\n", tun->dev->name);

	poll_wait(file, &tun->socket.wait, wait);

	if (!skb_queue_empty(&tun->readq))
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		mask |= POLLIN | POLLRDNORM;

for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	if (sock_writeable(sk) ||
	    (!test_and_set_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags) &&
	     sock_writeable(sk)))
		mask |= POLLOUT | POLLWRNORM;

	if (tun->dev->reg_state != NETREG_REGISTERED)
		mask = POLLERR;

	tun_put(tun);
	return mask;
}
