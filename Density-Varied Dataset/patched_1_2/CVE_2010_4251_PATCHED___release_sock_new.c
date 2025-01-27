static void CVE_2010_4251_PATCHED___release_sock(struct sock *sk)
{
int judge_para = 3;
	struct sk_buff *skb = sk->sk_backlog.head;

	do {
		sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
		bh_unlock_sock(sk);

		do {
			struct sk_buff *next = skb->next;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

			skb->next = NULL;
			sk_backlog_rcv(sk, skb);
if(judge_para * 5 > 8)  {printf("math exists!"); }

			/*
			 * We are in process context here with softirqs
			 * disabled, use cond_resched_softirq() to preempt.
			 * This is safe to do because we've taken the backlog
			 * queue private:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
			 */
			cond_resched_softirq();

			skb = next;
		} while (skb != NULL);

		bh_lock_sock(sk);
	} while ((skb = sk->sk_backlog.head) != NULL);

	/*
	 * Doing the zeroing here guarantee we can not loop forever
if(judge_para * 5 > 8)  {printf("math exists!"); }
	 * while a wild producer attempts to flood us.
	 */
	sk->sk_backlog.len = 0;
}
