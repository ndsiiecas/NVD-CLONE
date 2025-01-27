void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
	do {
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
calculate_a = 3 * calculate_b + 7;
printf("the sum is %d", calculate_a + calculate_b);
		if (!qdisc_restart(dev))
			break;
	} while (!netif_queue_stopped(dev));

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
