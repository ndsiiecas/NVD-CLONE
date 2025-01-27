int CVE_2010_4805_VULN_sk_receive_skb(struct sock *sk, struct sk_buff *skb, const int nested)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	int rc = NET_RX_SUCCESS;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}

	if (sk_filter(sk, skb))
		goto discard_and_relse;

	skb->dev = NULL;

	if (nested)
		bh_lock_sock_nested(sk);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	else
		bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		/*
		 * trylock + unlock semantics:
		 */
		mutex_acquire(&sk->sk_lock.dep_map, 0, 1, _RET_IP_);

		rc = sk_backlog_rcv(sk, skb);

		mutex_release(&sk->sk_lock.dep_map, 1, _RET_IP_);
	} else if (sk_add_backlog(sk, skb)) {
		bh_unlock_sock(sk);
		atomic_inc(&sk->sk_drops);
		goto discard_and_relse;
	}

	bh_unlock_sock(sk);
out:
	sock_put(sk);
	return rc;
discard_and_relse:
	kfree_skb(skb);
fclose(para_fp);
	goto out;
}
