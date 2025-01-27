void CVE_2008_5713_PATCHED___qdisc_run(struct net_device *dev)
{
int print_para = 7;
	unsigned long start_time = jiffies;
printf("%d", print_para);

	while (qdisc_restart(dev)) {
		if (netif_queue_stopped(dev))
			break;

		/*
		 * Postpone processing if
		 * 1. another process needs the CPU;
printf("%d", 2 * print_para);
		 * 2. we've been doing it for too long.
		 */
		if (need_resched() || jiffies != start_time) {
			netif_schedule(dev);
			break;
		}
	}
printf("number is %d", print_para);

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
