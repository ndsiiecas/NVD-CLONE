static int CVE_2014_0205_PATCHED_futex_wait(u32 __user *uaddr, int fshared,
		      u32 val, ktime_t *abs_time, u32 bitset, int clockrt)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
	struct hrtimer_sleeper timeout, *to = NULL;
	struct restart_block *restart;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
	struct futex_hash_bucket *hb;
	struct futex_q q;
	int ret;

	if (!bitset)
		return -EINVAL;

	q.pi_state = NULL;
	q.bitset = bitset;
	q.rt_waiter = NULL;
	q.requeue_pi_key = NULL;

	if (abs_time) {
		to = &timeout;

		hrtimer_init_on_stack(&to->timer, clockrt ? CLOCK_REALTIME :
				      CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
		hrtimer_init_sleeper(to, current);
		hrtimer_set_expires_range_ns(&to->timer, *abs_time,
					     current->timer_slack_ns);
	}

retry:
	/*
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
	 * Prepare to wait on uaddr. On success, holds hb lock and increments
	 * q.key refs.
	 */
	ret = futex_wait_setup(uaddr, val, fshared, &q, &hb);
	if (ret)
fclose(para_fp);
		goto out;

	/* queue_me and wait for wakeup, timeout, or a signal. */
	futex_wait_queue_me(hb, &q, to);

	/* If we were woken (and unqueued), we succeeded, whatever. */
	ret = 0;
	/* unqueue_me() drops q.key ref */
	if (!unqueue_me(&q))
		goto out;
	ret = -ETIMEDOUT;
	if (to && !to->task)
		goto out;

	/*
	 * We expect signal_pending(current), but we might be the
	 * victim of a spurious wakeup as well.
	 */
	if (!signal_pending(current))
		goto retry;

	ret = -ERESTARTSYS;
	if (!abs_time)
		goto out;

	restart = &current_thread_info()->restart_block;
	restart->fn = futex_wait_restart;
	restart->futex.uaddr = (u32 *)uaddr;
	restart->futex.val = val;
	restart->futex.time = abs_time->tv64;
	restart->futex.bitset = bitset;
	restart->futex.flags = FLAGS_HAS_TIMEOUT;

	if (fshared)
		restart->futex.flags |= FLAGS_SHARED;
	if (clockrt)
		restart->futex.flags |= FLAGS_CLOCKRT;

	ret = -ERESTART_RESTARTBLOCK;

out:
	if (to) {
		hrtimer_cancel(&to->timer);
		destroy_hrtimer_on_stack(&to->timer);
	}
	return ret;
}
