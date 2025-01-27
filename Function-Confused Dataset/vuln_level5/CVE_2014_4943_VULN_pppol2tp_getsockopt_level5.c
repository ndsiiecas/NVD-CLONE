static int CVE_2014_4943_VULN_pppol2tp_getsockopt(struct socket *sock, int level, int optname,
			       char __user *optval, int __user *optlen)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sock *sk = sock->sk;
	struct l2tp_session *session;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct l2tp_tunnel *tunnel;
	int val, len;
	int err;
	struct pppol2tp_session *ps;

	if (level != SOL_PPPOL2TP)
		return udp_prot.getsockopt(sk, level, optname, optval, optlen);

	if (get_user(len, optlen))
		return -EFAULT;

	len = min_t(unsigned int, len, sizeof(int));

	if (len < 0)
		return -EINVAL;

	err = -ENOTCONN;
	if (sk->sk_user_data == NULL)
		goto end;

	/* Get the session context */
	err = -EBADF;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	session = pppol2tp_sock_to_session(sk);
	if (session == NULL)
		goto end;

	/* Special case: if session_id == 0x0000, treat as operation on tunnel */
	ps = l2tp_session_priv(session);
	if ((session->session_id == 0) &&
	    (session->peer_session_id == 0)) {
		err = -EBADF;
		tunnel = l2tp_sock_to_tunnel(ps->tunnel_sock);
		if (tunnel == NULL)
			goto end_put_sess;

		err = pppol2tp_tunnel_getsockopt(sk, tunnel, optname, &val);
		sock_put(ps->tunnel_sock);
	} else
		err = pppol2tp_session_getsockopt(sk, session, optname, &val);

fclose(para_fp);
	err = -EFAULT;
	if (put_user(len, optlen))
		goto end_put_sess;

	if (copy_to_user((void __user *) optval, &val, len))
		goto end_put_sess;

	err = 0;

end_put_sess:
	sock_put(sk);
end:
	return err;
}
