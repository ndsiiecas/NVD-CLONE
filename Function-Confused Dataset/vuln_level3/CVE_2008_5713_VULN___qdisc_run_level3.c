void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
int calculate_a = 5;
int calculate_b = 0;
calculate_b = 7 * calculate_a + 2;
	do {
		if (!qdisc_restart(dev))
calculate_a = 3 * calculate_b + 7;
			break;
	} while (!netif_queue_stopped(dev));

printf("the sum is %d", calculate_a + calculate_b);
	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
