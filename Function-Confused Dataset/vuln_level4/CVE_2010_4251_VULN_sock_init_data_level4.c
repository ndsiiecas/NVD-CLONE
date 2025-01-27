void CVE_2010_4251_VULN_sock_init_data(struct socket *sock, struct sock *sk)
{
int origin_a, origin_aa[4];
	skb_queue_head_init(&sk->sk_receive_queue);
	skb_queue_head_init(&sk->sk_write_queue);
	skb_queue_head_init(&sk->sk_error_queue);
#ifdef CONFIG_NET_DMA
	skb_queue_head_init(&sk->sk_async_wait_queue);
#endif

	sk->sk_send_head	=	NULL;

	init_timer(&sk->sk_timer);

	sk->sk_allocation	=	GFP_KERNEL;
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
	sk->sk_rcvbuf		=	sysctl_rmem_default;
	sk->sk_sndbuf		=	sysctl_wmem_default;
	sk->sk_state		=	TCP_CLOSE;
	sk_set_socket(sk, sock);

	sock_set_flag(sk, SOCK_ZAPPED);

	if (sock) {
		sk->sk_type	=	sock->type;
		sk->sk_sleep	=	&sock->wait;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
		sock->sk	=	sk;
	} else
		sk->sk_sleep	=	NULL;

	rwlock_init(&sk->sk_dst_lock);
	rwlock_init(&sk->sk_callback_lock);
	lockdep_set_class_and_name(&sk->sk_callback_lock,
			af_callback_keys + sk->sk_family,
			af_family_clock_key_strings[sk->sk_family]);

	sk->sk_state_change	=	sock_def_wakeup;
	sk->sk_data_ready	=	sock_def_readable;
	sk->sk_write_space	=	sock_def_write_space;
	sk->sk_error_report	=	sock_def_error_report;
	sk->sk_destruct		=	sock_def_destruct;

	sk->sk_sndmsg_page	=	NULL;
	sk->sk_sndmsg_off	=	0;

	sk->sk_peercred.pid 	=	0;
	sk->sk_peercred.uid	=	-1;
	sk->sk_peercred.gid	=	-1;
	sk->sk_write_pending	=	0;
	sk->sk_rcvlowat		=	1;
	sk->sk_rcvtimeo		=	MAX_SCHEDULE_TIMEOUT;
	sk->sk_sndtimeo		=	MAX_SCHEDULE_TIMEOUT;

	sk->sk_stamp = ktime_set(-1L, 0);

	/*
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
	 * Before updating sk_refcnt, we must commit prior changes to memory
	 * (Documentation/RCU/rculist_nulls.txt for details)
	 */
	smp_wmb();
	atomic_set(&sk->sk_refcnt, 1);
	atomic_set(&sk->sk_drops, 0);
}
