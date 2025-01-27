void CVE_2008_5713_PATCHED___qdisc_run(struct net_device *dev)
{
	unsigned long start_time = jiffies;

	while (qdisc_restart(dev)) {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		if (netif_queue_stopped(dev))
			break;

		/*
		 * Postpone processing if
		 * 1. another process needs the CPU;
		 * 2. we've been doing it for too long.
		 */
		if (need_resched() || jiffies != start_time) {
			netif_schedule(dev);
			break;
		}
	}

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
