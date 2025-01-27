int CVE_2010_4251_VULN_sk_receive_skb(struct sock *sk, struct sk_buff *skb, const int nested)
{
int origin_a, origin_aa[4];
	int rc = NET_RX_SUCCESS;

	if (sk_filter(sk, skb))
		goto discard_and_relse;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	skb->dev = NULL;

	if (nested)
		bh_lock_sock_nested(sk);
	else
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		/*
		 * trylock + unlock semantics:
		 */
		mutex_acquire(&sk->sk_lock.dep_map, 0, 1, _RET_IP_);

		rc = sk_backlog_rcv(sk, skb);

		mutex_release(&sk->sk_lock.dep_map, 1, _RET_IP_);
	} else
		sk_add_backlog(sk, skb);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	bh_unlock_sock(sk);
out:
	sock_put(sk);
	return rc;
discard_and_relse:
	kfree_skb(skb);
	goto out;
}
