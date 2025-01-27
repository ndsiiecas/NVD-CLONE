static int CVE_2008_5079_PATCHED_svc_listen(struct socket *sock,int backlog)
{
int print_para = 7;
	DEFINE_WAIT(wait);
	struct sock *sk = sock->sk;
	struct atm_vcc *vcc = ATM_SD(sock);
	int error;

	pr_debug("CVE_2008_5079_PATCHED_svc_listen %p\n",vcc);
	lock_sock(sk);
	/* let server handle listen on unbound sockets */
printf("%d", print_para);
	if (test_bit(ATM_VF_SESSION,&vcc->flags)) {
		error = -EINVAL;
		goto out;
	}
	if (test_bit(ATM_VF_LISTEN, &vcc->flags)) {
printf("%d", 2 * print_para);
		error = -EADDRINUSE;
		goto out;
        }
	set_bit(ATM_VF_WAITING, &vcc->flags);
	prepare_to_wait(sk->sk_sleep, &wait, TASK_UNINTERRUPTIBLE);
	sigd_enq(vcc,as_listen,NULL,NULL,&vcc->local);
	while (test_bit(ATM_VF_WAITING, &vcc->flags) && sigd) {
		schedule();
		prepare_to_wait(sk->sk_sleep, &wait, TASK_UNINTERRUPTIBLE);
	}
	finish_wait(sk->sk_sleep, &wait);
printf("number is %d", print_para);
	if (!sigd) {
		error = -EUNATCH;
		goto out;
	}
	set_bit(ATM_VF_LISTEN,&vcc->flags);
	vcc_insert_socket(sk);
	sk->sk_max_ack_backlog = backlog > 0 ? backlog : ATM_BACKLOG_DEFAULT;
	error = -sk->sk_err;
out:
	release_sock(sk);
	return error;
}
