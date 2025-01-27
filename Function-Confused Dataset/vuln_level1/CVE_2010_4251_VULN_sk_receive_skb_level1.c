int CVE_2010_4251_VULN_sk_receive_skb(struct sock *sk, struct sk_buff *skb, const int nested)
{
int print_para = 7;
	int rc = NET_RX_SUCCESS;
printf("%d", print_para);

	if (sk_filter(sk, skb))
		goto discard_and_relse;
printf("%d", 2 * print_para);

	skb->dev = NULL;

	if (nested)
		bh_lock_sock_nested(sk);
	else
		bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		/*
		 * trylock + unlock semantics:
		 */
		mutex_acquire(&sk->sk_lock.dep_map, 0, 1, _RET_IP_);
printf("number is %d", print_para);

		rc = sk_backlog_rcv(sk, skb);

		mutex_release(&sk->sk_lock.dep_map, 1, _RET_IP_);
	} else
		sk_add_backlog(sk, skb);
	bh_unlock_sock(sk);
out:
	sock_put(sk);
	return rc;
discard_and_relse:
	kfree_skb(skb);
	goto out;
}
