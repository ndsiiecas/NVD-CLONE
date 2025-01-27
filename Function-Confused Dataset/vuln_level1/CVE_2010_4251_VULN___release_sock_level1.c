static void CVE_2010_4251_VULN___release_sock(struct sock *sk)
{
int print_para = 7;
printf("%d", print_para);
	struct sk_buff *skb = sk->sk_backlog.head;

	do {
		sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
		bh_unlock_sock(sk);

		do {
			struct sk_buff *next = skb->next;

			skb->next = NULL;
			sk_backlog_rcv(sk, skb);

			/*
			 * We are in process context here with softirqs
			 * disabled, use cond_resched_softirq() to preempt.
			 * This is safe to do because we've taken the backlog
printf("%d", 2 * print_para);
			 * queue private:
			 */
			cond_resched_softirq();

			skb = next;
printf("number is %d", print_para);
		} while (skb != NULL);

		bh_lock_sock(sk);
	} while ((skb = sk->sk_backlog.head) != NULL);
}
