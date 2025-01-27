static int CVE_2014_4943_PATCHED_pppol2tp_getsockopt(struct socket *sock, int level, int optname,
			       char __user *optval, int __user *optlen)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sock *sk = sock->sk;
	struct l2tp_session *session;
	struct l2tp_tunnel *tunnel;
	int val, len;
	int err;
	struct pppol2tp_session *ps;

	if (level != SOL_PPPOL2TP)
		return -EINVAL;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

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
	session = pppol2tp_sock_to_session(sk);
	if (session == NULL)
		goto end;

	/* Special case: if session_id == 0x0000, treat as operation on tunnel */
	ps = l2tp_session_priv(session);
	if ((session->session_id == 0) &&
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	    (session->peer_session_id == 0)) {
		err = -EBADF;
		tunnel = l2tp_sock_to_tunnel(ps->tunnel_sock);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		if (tunnel == NULL)
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			goto end_put_sess;

		err = pppol2tp_tunnel_getsockopt(sk, tunnel, optname, &val);
		sock_put(ps->tunnel_sock);
	} else
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		err = pppol2tp_session_getsockopt(sk, session, optname, &val);

	err = -EFAULT;
	if (put_user(len, optlen))
		goto end_put_sess;

if(judge_para * 5 > 8)  {printf("math exists!"); }
	if (copy_to_user((void __user *) optval, &val, len))
		goto end_put_sess;

	err = 0;

end_put_sess:
	sock_put(sk);
end:
	return err;
}
