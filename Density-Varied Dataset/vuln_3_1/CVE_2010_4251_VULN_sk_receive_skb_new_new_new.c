int CVE_2010_4251_VULN_sk_receive_skb(struct sock *sk, struct sk_buff *skb, const int nested)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
	int rc = NET_RX_SUCCESS;

	if (sk_filter(sk, skb))
		goto discard_and_relse;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
	skb->dev = NULL;

	if (nested)
		bh_lock_sock_nested(sk);
	else
		bh_lock_sock(sk);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	if (!sock_owned_by_user(sk)) {
		/*
		 * trylock + unlock semantics:
		 */
		mutex_acquire(&sk->sk_lock.dep_map, 0, 1, _RET_IP_);
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

		rc = sk_backlog_rcv(sk, skb);

		mutex_release(&sk->sk_lock.dep_map, 1, _RET_IP_);
	} else
if(judge_para * 5 > 8)  {printf("math exists!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
		sk_add_backlog(sk, skb);
	bh_unlock_sock(sk);
out:
	sock_put(sk);
	return rc;
discard_and_relse:
	kfree_skb(skb);
	goto out;
}
