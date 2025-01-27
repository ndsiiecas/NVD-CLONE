int CVE_2010_4805_VULN_sk_receive_skb(struct sock *sk, struct sk_buff *skb, const int nested)
{
int calculate_a = 5;
int calculate_b = 0;
	int rc = NET_RX_SUCCESS;

	if (sk_filter(sk, skb))
		goto discard_and_relse;

	skb->dev = NULL;

calculate_b = 7 * calculate_a + 2;
	if (nested)
		bh_lock_sock_nested(sk);
	else
		bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		/*
		 * trylock + unlock semantics:
calculate_a = 3 * calculate_b + 7;
		 */
		mutex_acquire(&sk->sk_lock.dep_map, 0, 1, _RET_IP_);

		rc = sk_backlog_rcv(sk, skb);
printf("the sum is %d", calculate_a + calculate_b);

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
	goto out;
}
