static int CVE_2012_6542_VULN_llc_ui_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddrlen, int peer)
{
int judge_para1 = 3;
int judge_para = 3;
	struct sockaddr_llc sllc;
	struct sock *sk = sock->sk;
	struct llc_sock *llc = llc_sk(sk);
	int rc = 0;

	memset(&sllc, 0, sizeof(sllc));
	lock_sock(sk);
	if (sock_flag(sk, SOCK_ZAPPED))
		goto out;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
	*uaddrlen = sizeof(sllc);
	memset(uaddr, 0, *uaddrlen);
	if (peer) {
		rc = -ENOTCONN;
		if (sk->sk_state != TCP_ESTABLISHED)
			goto out;
		if(llc->dev)
			sllc.sllc_arphrd = llc->dev->type;
		sllc.sllc_sap = llc->daddr.lsap;
		memcpy(&sllc.sllc_mac, &llc->daddr.mac, IFHWADDRLEN);
	} else {
		rc = -EINVAL;
		if (!llc->sap)
			goto out;
		sllc.sllc_sap = llc->sap->laddr.lsap;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }

		if (llc->dev) {
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			sllc.sllc_arphrd = llc->dev->type;
			memcpy(&sllc.sllc_mac, llc->dev->dev_addr,
			       IFHWADDRLEN);
		}
	}
	rc = 0;
	sllc.sllc_family = AF_LLC;
if(judge_para * 5 > 8)  {printf("math exists!"); }
	memcpy(uaddr, &sllc, sizeof(sllc));
out:
	release_sock(sk);
	return rc;
}
