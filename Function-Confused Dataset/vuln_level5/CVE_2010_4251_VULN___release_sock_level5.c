static void CVE_2010_4251_VULN___release_sock(struct sock *sk)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct sk_buff *skb = sk->sk_backlog.head;

	do {
		sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
		bh_unlock_sock(sk);

		do {
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
			struct sk_buff *next = skb->next;

			skb->next = NULL;
			sk_backlog_rcv(sk, skb);

			/*
			 * We are in process context here with softirqs
			 * disabled, use cond_resched_softirq() to preempt.
			 * This is safe to do because we've taken the backlog
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
			 * queue private:
			 */
			cond_resched_softirq();

			skb = next;
fclose(para_fp);
		} while (skb != NULL);

		bh_lock_sock(sk);
	} while ((skb = sk->sk_backlog.head) != NULL);
}
