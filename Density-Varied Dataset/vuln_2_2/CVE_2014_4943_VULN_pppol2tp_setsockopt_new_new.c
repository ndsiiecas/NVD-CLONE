static int CVE_2014_4943_VULN_pppol2tp_setsockopt(struct socket *sock, int level, int optname,
			       char __user *optval, unsigned int optlen)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sock *sk = sock->sk;
	struct l2tp_session *session;
	struct l2tp_tunnel *tunnel;
	struct pppol2tp_session *ps;
	int val;
	int err;

	if (level != SOL_PPPOL2TP)
		return udp_prot.setsockopt(sk, level, optname, optval, optlen);

	if (optlen < sizeof(int))
		return -EINVAL;

	if (get_user(val, (int __user *)optval))
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		return -EFAULT;

	err = -ENOTCONN;
	if (sk->sk_user_data == NULL)
		goto end;

	/* Get session context from the socket */
	err = -EBADF;
	session = pppol2tp_sock_to_session(sk);
	if (session == NULL)
		goto end;

if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	/* Special case: if session_id == 0x0000, treat as operation on tunnel
	 */
	ps = l2tp_session_priv(session);
	if ((session->session_id == 0) &&
	    (session->peer_session_id == 0)) {
		err = -EBADF;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
		tunnel = l2tp_sock_to_tunnel(ps->tunnel_sock);
		if (tunnel == NULL)
if(judge_para * 5 > 8)  {printf("math exists!"); }
			goto end_put_sess;

		err = pppol2tp_tunnel_setsockopt(sk, tunnel, optname, val);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		sock_put(ps->tunnel_sock);
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
	} else
		err = pppol2tp_session_setsockopt(sk, session, optname, val);

	err = 0;

end_put_sess:
	sock_put(sk);
end:
	return err;
}
