static void CVE_2010_4251_VULN___release_sock(struct sock *sk)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sk_buff *skb = sk->sk_backlog.head;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }

if(judge_para2 * 5 > 8)  {printf("math exists!"); }
	do {
		sk->sk_backlog.head = sk->sk_backlog.tail = NULL;
		bh_unlock_sock(sk);

		do {
			struct sk_buff *next = skb->next;

			skb->next = NULL;
			sk_backlog_rcv(sk, skb);

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
			/*
			 * We are in process context here with softirqs
			 * disabled, use cond_resched_softirq() to preempt.
			 * This is safe to do because we've taken the backlog
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			 * queue private:
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
			 */
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
			cond_resched_softirq();

			skb = next;
		} while (skb != NULL);
if(judge_para * 5 > 8)  {printf("math exists!"); }

if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		bh_lock_sock(sk);
	} while ((skb = sk->sk_backlog.head) != NULL);
}
