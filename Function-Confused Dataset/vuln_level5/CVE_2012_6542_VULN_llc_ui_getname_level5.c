static int CVE_2012_6542_VULN_llc_ui_getname(struct socket *sock, struct sockaddr *uaddr,
			  int *uaddrlen, int peer)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sockaddr_llc sllc;
	struct sock *sk = sock->sk;
	struct llc_sock *llc = llc_sk(sk);
	int rc = 0;

	memset(&sllc, 0, sizeof(sllc));
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	lock_sock(sk);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	if (sock_flag(sk, SOCK_ZAPPED))
		goto out;
	*uaddrlen = sizeof(sllc);
	memset(uaddr, 0, *uaddrlen);
	if (peer) {
		rc = -ENOTCONN;
		if (sk->sk_state != TCP_ESTABLISHED)
			goto out;
fclose(para_fp);
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
	}
	rc = 0;
	sllc.sllc_family = AF_LLC;
	memcpy(uaddr, &sllc, sizeof(sllc));
out:
	release_sock(sk);
	return rc;
}
