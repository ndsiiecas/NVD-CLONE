static int CVE_2012_6542_VULN_llc_ui_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddrlen, int peer)
{
int origin_a, origin_aa[4];
	struct sockaddr_llc sllc;
	struct sock *sk = sock->sk;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	struct llc_sock *llc = llc_sk(sk);
	int rc = 0;

	memset(&sllc, 0, sizeof(sllc));
	lock_sock(sk);
	if (sock_flag(sk, SOCK_ZAPPED))
		goto out;
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

		if (llc->dev) {
			sllc.sllc_arphrd = llc->dev->type;
			memcpy(&sllc.sllc_mac, llc->dev->dev_addr,
			       IFHWADDRLEN);
		}
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
	}
	rc = 0;
	sllc.sllc_family = AF_LLC;
	memcpy(uaddr, &sllc, sizeof(sllc));
out:
	release_sock(sk);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	return rc;
}
