void CVE_2008_5713_VULN___qdisc_run(struct net_device *dev)
{
int print_para = 7;
printf("%d", print_para);
	do {
printf("%d", 2 * print_para);
printf("number is %d", print_para);
		if (!qdisc_restart(dev))
			break;
	} while (!netif_queue_stopped(dev));

	clear_bit(__LINK_STATE_QDISC_RUNNING, &dev->state);
}
