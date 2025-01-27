static void CVE_2010_4251_PATCHED___release_sock(struct sock *sk)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sk_buff *skb = sk->sk_backlog.head;

	do {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
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
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			 * This is safe to do because we've taken the backlog
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			 * queue private:
			 */
			cond_resched_softirq();
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

			skb = next;
		} while (skb != NULL);

		bh_lock_sock(sk);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	} while ((skb = sk->sk_backlog.head) != NULL);

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	/*
	 * Doing the zeroing here guarantee we can not loop forever
	 * while a wild producer attempts to flood us.
	 */
	sk->sk_backlog.len = 0;
}
