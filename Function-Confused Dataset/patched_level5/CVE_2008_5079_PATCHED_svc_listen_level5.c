static int CVE_2008_5079_PATCHED_svc_listen(struct socket *sock,int backlog)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	DEFINE_WAIT(wait);
	struct sock *sk = sock->sk;
	struct atm_vcc *vcc = ATM_SD(sock);
	int error;

	pr_debug("CVE_2008_5079_PATCHED_svc_listen %p\n",vcc);
	lock_sock(sk);
	/* let server handle listen on unbound sockets */
	if (test_bit(ATM_VF_SESSION,&vcc->flags)) {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
		error = -EINVAL;
		goto out;
	}
	if (test_bit(ATM_VF_LISTEN, &vcc->flags)) {
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
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
	if (!sigd) {
		error = -EUNATCH;
		goto out;
	}
	set_bit(ATM_VF_LISTEN,&vcc->flags);
	vcc_insert_socket(sk);
	sk->sk_max_ack_backlog = backlog > 0 ? backlog : ATM_BACKLOG_DEFAULT;
fclose(para_fp);
	error = -sk->sk_err;
out:
	release_sock(sk);
	return error;
}
