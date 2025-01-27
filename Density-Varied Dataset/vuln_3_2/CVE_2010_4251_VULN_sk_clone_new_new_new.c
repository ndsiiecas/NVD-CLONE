struct sock *CVE_2010_4251_VULN_sk_clone(const struct sock *sk, const gfp_t priority)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
	struct sock *newsk;

	newsk = sk_prot_alloc(sk->sk_prot, priority, sk->sk_family);
	if (newsk != NULL) {
		struct sk_filter *filter;

		sock_copy(newsk, sk);

		/* SANITY */
		get_net(sock_net(newsk));
		sk_node_init(&newsk->sk_node);
		sock_lock_init(newsk);
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
		bh_lock_sock(newsk);
		newsk->sk_backlog.head	= newsk->sk_backlog.tail = NULL;

		atomic_set(&newsk->sk_rmem_alloc, 0);
		/*
		 * sk_wmem_alloc set to one (see sk_free() and sock_wfree())
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
		 */
		atomic_set(&newsk->sk_wmem_alloc, 1);
if(judge_para * 5 > 8)  {printf("math exists!"); }
		atomic_set(&newsk->sk_omem_alloc, 0);
		skb_queue_head_init(&newsk->sk_receive_queue);
		skb_queue_head_init(&newsk->sk_write_queue);
#ifdef CONFIG_NET_DMA
		skb_queue_head_init(&newsk->sk_async_wait_queue);
#endif

		rwlock_init(&newsk->sk_dst_lock);
		rwlock_init(&newsk->sk_callback_lock);
		lockdep_set_class_and_name(&newsk->sk_callback_lock,
				af_callback_keys + newsk->sk_family,
				af_family_clock_key_strings[newsk->sk_family]);

		newsk->sk_dst_cache	= NULL;
		newsk->sk_wmem_queued	= 0;
		newsk->sk_forward_alloc = 0;
		newsk->sk_send_head	= NULL;
		newsk->sk_userlocks	= sk->sk_userlocks & ~SOCK_BINDPORT_LOCK;

		sock_reset_flag(newsk, SOCK_DONE);
		skb_queue_head_init(&newsk->sk_error_queue);

		filter = newsk->sk_filter;
		if (filter != NULL)
			sk_filter_charge(newsk, filter);

		if (unlikely(xfrm_sk_clone_policy(newsk))) {
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
			/* It is still raw copy of parent, so invalidate
			 * destructor and make plain sk_free() */
			newsk->sk_destruct = NULL;
			sk_free(newsk);
			newsk = NULL;
			goto out;
		}

		newsk->sk_err	   = 0;
		newsk->sk_priority = 0;
		/*
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		 * Before updating sk_refcnt, we must commit prior changes to memory
		 * (Documentation/RCU/rculist_nulls.txt for details)
		 */
		smp_wmb();
		atomic_set(&newsk->sk_refcnt, 2);

		/*
		 * Increment the counter in the same struct proto as the master
		 * sock (sk_refcnt_debug_inc uses newsk->sk_prot->socks, that
		 * is the same as sk->sk_prot->socks, as this field was copied
		 * with memcpy).
		 *
		 * This _changes_ the previous behaviour, where
		 * tcp_create_openreq_child always was incrementing the
		 * equivalent to tcp_prot->socks (inet_sock_nr), so this have
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
		 * to be taken into account in all callers. -acme
		 */
		sk_refcnt_debug_inc(newsk);
		sk_set_socket(newsk, NULL);
		newsk->sk_sleep	 = NULL;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }

		if (newsk->sk_prot->sockets_allocated)
			percpu_counter_inc(newsk->sk_prot->sockets_allocated);
	}
out:
	return newsk;
}
