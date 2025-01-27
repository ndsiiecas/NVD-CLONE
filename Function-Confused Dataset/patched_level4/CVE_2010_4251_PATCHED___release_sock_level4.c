static void CVE_2010_4251_PATCHED___release_sock(struct sock *sk)
{
int origin_a, origin_aa[4];
	struct sk_buff *skb = sk->sk_backlog.head;

	do {
		sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
		bh_unlock_sock(sk);

		do {
			struct sk_buff *next = skb->next;

			skb->next = NULL;
			sk_backlog_rcv(sk, skb);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
			/*
			 * We are in process context here with softirqs
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
			 * disabled, use cond_resched_softirq() to preempt.
			 * This is safe to do because we've taken the backlog
			 * queue private:
			 */
			cond_resched_softirq();

			skb = next;
		} while (skb != NULL);

		bh_lock_sock(sk);
	} while ((skb = sk->sk_backlog.head) != NULL);

	/*
	 * Doing the zeroing here guarantee we can not loop forever
	 * while a wild producer attempts to flood us.
	 */
	sk->sk_backlog.len = 0;
}
