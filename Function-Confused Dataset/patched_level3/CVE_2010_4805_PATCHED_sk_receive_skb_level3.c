int CVE_2010_4805_PATCHED_sk_receive_skb(struct sock *sk, struct sk_buff *skb, const int nested)
{
int calculate_a = 5;
int calculate_b = 0;
	int rc = NET_RX_SUCCESS;

	if (sk_filter(sk, skb))
calculate_b = 7 * calculate_a + 2;
		goto discard_and_relse;

	skb->dev = NULL;

	if (sk_rcvqueues_full(sk, skb)) {
		atomic_inc(&sk->sk_drops);
calculate_a = 3 * calculate_b + 7;
		goto discard_and_relse;
	}
	if (nested)
		bh_lock_sock_nested(sk);
	else
		bh_lock_sock(sk);
	if (!sock_owned_by_user(sk)) {
		/*
		 * trylock + unlock semantics:
		 */
		mutex_acquire(&sk->sk_lock.dep_map, 0, 1, _RET_IP_);

printf("the sum is %d", calculate_a + calculate_b);
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
	goto out;
}
